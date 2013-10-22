/*-------------------------------------------------------------------------*\
  <serialeditor.C> -- Serialized editor implementation file

  Date      Programmer  Description
  10/18/13  Dennis      Created.
\*-------------------------------------------------------------------------*/

#include "btconst.h"
#include "serialeditor.h"
#include <algorithm>
#include <sstream>

BTSerializedEditor::BTSerializedEditor(int num, const char **d, const char **f)
 : entries(num), description(d), field(f)
{
}

BTSerializedEditor::~BTSerializedEditor()
{
}

void BTSerializedEditor::edit(BTDisplay &d, ObjectSerializer &serial)
{
 BTDisplayConfig *oldConfig = d.getConfig();
 BTDisplayConfig config;
 XMLSerializer parser;
 config.serialize(&parser);
 parser.parse("data/specialedit.xml", true);
 d.setConfig(&config);
 int start(0);
 int current(0);
 BitField active;
 std::vector<BTDisplay::selectItem> list(entries);
 initActive(serial, active);
 int len = setup(serial, active, list);
 d.addSelection(list.data(), len, start, current);
 int key;
 while (27 != (key = d.process()))
 {
  d.clearText();
  XMLAction *curField = serial.find(field[list[current].value], NULL);
  if (curField)
  {
   switch (curField->getType())
   {
    case XMLTYPE_STDSTRING:
    {
     std::string val = curField->createString();
     d.addReadString(std::string(description[list[current].value]) + ": ", 100, val);
     key = d.process();
     if ('\r' == key)
      *(reinterpret_cast<std::string*>(curField->object)) = val;
     break;
    }
    case XMLTYPE_STRING:
    {
     std::string val = curField->createString();
     d.addReadString(std::string(description[list[current].value]) + ": ", 100, val);
     key = d.process();
     if ('\r' == key)
     {
      char *str = *(reinterpret_cast<char**>(curField->object));
      if (str)
      {
       delete [] str;
      }
      int len = val.length();
      str = new char[len + 1];
      strncpy(str, val.c_str(), len);
      str[len] = 0;
      *(reinterpret_cast<char**>(curField->object)) = str;
     }
     break;
    }
    case XMLTYPE_BOOL:
    {
     BTDisplay::selectItem vals[2];
     vals[0].name = "false";
     vals[1].name = "true";
     int lookupStart(0);
     int lookupCurrent((*(reinterpret_cast<bool*>(curField->object)) ? 1 : 0));
     d.addSelection(vals, 2, lookupStart, lookupCurrent);
     if (27 != d.process())
     {
      *(reinterpret_cast<bool*>(curField->object)) = lookupCurrent;
     }
     break;
    }
    case XMLTYPE_BITFIELD:
    {
     ValueLookup *lookup = reinterpret_cast<ValueLookup*>(curField->data);
     BitField *bits = reinterpret_cast<BitField*>(curField->object);
     BTDisplay::selectItem lookupItem[lookup->size()];
     for (int i = 0; i < lookup->size(); ++i)
     {
      lookupItem[i].name = lookup->getName(i);
      if (bits->isSet(i))
       lookupItem[i].first = '*';
     }
     int lookupStart(0);
     int lookupCurrent(0);
     d.addSelection(lookupItem, lookup->size(), lookupStart, lookupCurrent);
     int key;
     while (27 != (key = d.process()))
     {
      if (bits->toggle(lookupCurrent))
       lookupItem[lookupCurrent].first = '*';
      else
       lookupItem[lookupCurrent].first = 0;
     }
     break;
    }
    case XMLTYPE_INT:
    {
     if (curField->data)
     {
      ValueLookup *lookup = reinterpret_cast<ValueLookup*>(curField->data);
      bool extra = ((curField->extra == EXTRA_NONE) ? false : true);
      BTDisplay::selectItem lookupItem[lookup->size() + (extra ? 1 : 0)];
      if (extra)
       lookupItem[0].name = curField->extraText;
      for (int i = 0; i < lookup->size(); ++i)
       lookupItem[i + (extra ? 1 : 0)].name = lookup->getName(i);
      int lookupStart(0);
      int lookupCurrent((*(reinterpret_cast<int*>(curField->object))) + (extra ? 1 : 0));
      d.addSelection(lookupItem, lookup->size() + (extra ? 1 : 0), lookupStart, lookupCurrent);
      if (27 != d.process())
      {
       *(reinterpret_cast<int*>(curField->object)) = lookupCurrent - (extra ? 1 : 0);
      }
     }
     else
     {
      std::string val = curField->createString();
      d.addReadString(std::string(description[list[current].value]) + ": ", 100, val);
      key = d.process();
      if ('\r' == key)
       *(reinterpret_cast<int*>(curField->object)) = atol(val.c_str());
     }
     break;
    }
    case XMLTYPE_INT16:
    {
     std::string val = curField->createString();
     d.addReadString(std::string(description[list[current].value]) + ": ", 100, val);
     key = d.process();
     if ('\r' == key)
      *(reinterpret_cast<int16_t*>(curField->object)) = atol(val.c_str());
     break;
    }
    case XMLTYPE_OBJECT:
    {
     XMLObject *obj = reinterpret_cast<XMLObject*>(curField->object);
     BTDice *dice = dynamic_cast<BTDice*>(obj);
     if (dice)
     {
      std::ostringstream stream;
      stream << dice->getNumber();
      std::string val = stream.str();
      d.addReadString(std::string(description[list[current].value]) + "- Number of Dice: ", 100, val);
      key = d.process();
      if ('\r' == key)
       dice->setNumber(atol(val.c_str()));
      d.clearText();
      stream.str("");
      stream << dice->getType();
      val = stream.str();
      d.addReadString(std::string(description[list[current].value]) + "- Type of Dice: ", 100, val);
      key = d.process();
      if ('\r' == key)
       dice->setType(atol(val.c_str()));
      d.clearText();
      stream.str("");
      stream << dice->getModifier();
      val = stream.str();
      d.addReadString(std::string(description[list[current].value]) + "- Modifier to Roll: ", 100, val);
      key = d.process();
      if ('\r' == key)
       dice->setModifier(atol(val.c_str()));
     }
     else
      printf("Unsuppported type: %d\n", curField->getType());
     break;
    }
    default:
     printf("Unsuppported type: %d\n", curField->getType());
     break;
   }
   d.clearText();
   if (curField->getType() == XMLTYPE_OBJECT)
   {
    XMLObject *obj = reinterpret_cast<XMLObject*>(curField->object);
    BTDice *dice = dynamic_cast<BTDice*>(obj);
    if (dice)
     list[current].name = std::string(description[list[current].value]) + ": " + dice->createString();
   }
   else
   {
    list[current].name = std::string(description[list[current].value]) + ": " + curField->createString();
   }
  }
  if (updateActive(serial, active, list[current].value))
   len = setup(serial, active, list);
  d.addSelection(list.data(), len, start, current);
 }
 d.clearText();
 d.setConfig(oldConfig);
}

void BTSerializedEditor::initActive(ObjectSerializer &serial, BitField &active)
{
 for (int i = 0; i < entries; ++i)
  active.set(i);
}

int BTSerializedEditor::setup(ObjectSerializer &serial, BitField &active, std::vector<BTDisplay::selectItem> &items)
{
 int current = 0;
 for (int i = 0; i < entries; ++i)
 {
  if (!active.isSet(i))
   continue;
  XMLAction *curField = serial.find(field[i], NULL);
  if (curField->getType() == XMLTYPE_OBJECT)
  {
   XMLObject *obj = reinterpret_cast<XMLObject*>(curField->object);
   BTDice *dice = dynamic_cast<BTDice*>(obj);
   if (dice)
   {
    items[current].name = std::string(description[i]) + ": " + dice->createString();
    items[current].value = i;
    ++current;
   }
  }
  else
  {
   items[current].name = std::string(description[i]) + ": " + curField->createString();
   items[current].value = i;
   ++current;
  }
 }
 return current;
}

bool BTSerializedEditor::updateActive(ObjectSerializer &serial, BitField &active, int modField)
{
 return false;
}

BTMapPropertiesEditor::BTMapPropertiesEditor()
 : BTSerializedEditor(FIELDS_MAP, mapDescription, mapField)
{
}

const char *BTMapPropertiesEditor::mapDescription[FIELDS_MAP] = { "Name", "Type", "Light", "Monster Level" };
const char *BTMapPropertiesEditor::mapField[FIELDS_MAP] = { "name", "type", "light", "monsterLevel" };

BTItemEditor::BTItemEditor()
 : BTSerializedEditor(FIELDS_ITEM, itemDescription, itemField)
{
}

const char *BTItemEditor::itemDescription[FIELDS_ITEM] = { "Name", "Type", "User Class", "Price", "Armor Plus", "Hit Plus", "Damage Dice", "X-Special", "Likelihood of X-Special", "Times Usable", "Consumed", "Spell Cast", "Cause", "Effect" };
const char *BTItemEditor::itemField[FIELDS_ITEM] = { "name", "type", "allowedJob", "price", "armorPlus", "hitPlus", "damage", "xSpecial", "chanceXSpecial", "timesUsable", "consume", "spell", "cause", "effect" };

BTMonsterEditor::BTMonsterEditor()
 : BTSerializedEditor(FIELDS_MONSTER, monsterDescription, monsterField)
{
}

const char *BTMonsterEditor::monsterDescription[FIELDS_MONSTER] = { "Name", "Plural", "Picture", "Gender", "Level", "Starting Distance", "Moves Per Round", "Rate of Attacks", "Base AC", "Upper Limit Appearing", "Hit Points", "Thaumaturigal Resistance", "Gold", "Wandering", "Attack Msg.", "Damage", "Extra Damage", "Ranged Type", "Ranged Spell", "Ranged Message", "Range", "Ranged Damage", "Ranged X-Damage" };
 const char *BTMonsterEditor::monsterField[FIELDS_MONSTER] = { "name", "pluralName", "picture", "gender", "level", "startDistance", "move", "rateAttacks", "ac", "maxAppearing", "hp", "magicResistance", "gold", "wandering", "meleeMessage", "meleeDamage", "meleeExtra", "rangedType", "rangedSpellName", "rangedMessage", "range", "rangedDamage", "rangedExtra" };

BTSpellEditor::BTSpellEditor()
 : BTSerializedEditor(FIELDS_SPELL, spellDescription, spellField)
{
}

void BTSpellEditor::initActive(ObjectSerializer &serial, BitField &active)
{
 for (int i = 0; i < entries; ++i)
 {
  if (i == 5)
  {
   XMLAction *curField = serial.find("type", NULL);
   if ((*(reinterpret_cast<int*>(curField->object)) == BTSPELLTYPE_SUMMONMONSTER) ||
    (*(reinterpret_cast<int*>(curField->object)) == BTSPELLTYPE_SUMMONILLUSION))
   {
    active.set(i);
   }
   else
    active.clear(i);
  }
  else
   active.set(i);
 }
}

bool BTSpellEditor::updateActive(ObjectSerializer &serial, BitField &active, int modField)
{
 if (modField == 4)
 {
  BitField old = active;
  XMLAction *curField = serial.find("type", NULL);
  if ((*(reinterpret_cast<int*>(curField->object)) == BTSPELLTYPE_SUMMONMONSTER) ||
   (*(reinterpret_cast<int*>(curField->object)) == BTSPELLTYPE_SUMMONILLUSION))
  {
   if (!active.isSet(5))
   {
    active.set(5);
    XMLAction *extraField = serial.find("extra", NULL);
    *(reinterpret_cast<int*>(extraField->object)) = 0;
   }
  }
  else
   active.clear(5);
  return !(active == old);
 }
 return false;
}

const char *BTSpellEditor::spellDescription[FIELDS_SPELL] = { "Name", "Code", "Mage Class", "Level", "Type", "Monster", "Points Needed" };
const char *BTSpellEditor::spellField[FIELDS_SPELL] = { "name", "code", "caster", "level", "type", "extraMonster", "sp" };
