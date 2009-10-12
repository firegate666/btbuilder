/*-------------------------------------------------------------------------*\
  <skill.C> -- Skill implementation file

  Date      Programmer  Description
  10/11/09  Dennis      Created.
\*-------------------------------------------------------------------------*/

#include "skill.h"
#include <stdio.h>

char *use[] =
{
 "autocombat",
 "combat",
 "any",
 "magic",
 "special"
};
ArrayLookup useLookup(5, use);
ArrayLookup effectLookup(BT_MONSTEREXTRADAMAGE, extraDamage);
char *specialSkill[] =
{
 "disarm",
 "hide",
 "song"
};
ArrayLookup specialLookup(3, specialSkill);

void BTSkill::serialize(ObjectSerializer* s)
{
 s->add("name", &name);
 s->add("use", &use, NULL, &useLookup);
 s->add("effect", &effect, NULL, &effectLookup);
 s->add("special", &special, NULL, &specialLookup);
}

void BTSkill::readXML(const char *filename, XMLVector<BTSkill*> &skill)
{
 XMLSerializer parser;
 parser.add("skill", &skill, &BTSkill::create);
 parser.parse(filename, true);
}

std::string BTSkillList::getName(int index)
{
 if ((size() > index) && (index >= 0))
  return operator[](index)->name;
 else
  return "---";
}

int BTSkillList::getIndex(std::string name)
{
 for (int i = 0; i < size(); ++i)
  if (strcmp(name.c_str(), operator[](i)->name) == 0)
   return i;
 return -1;
}