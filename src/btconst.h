#ifndef __BTCONST_H
#define __BTCONST_H
/*-------------------------------------------------------------------------*\
  <btconst.h> -- Bt Builder constants header file.

  Date      Programmer  Description
  11/20/00  Dennis      Created.
\*-------------------------------------------------------------------------*/

class ArrayLookup;
class PairLookup;

#define BT_SPELLTYPES_FULL 42
#define BT_SPELLTYPES_USED 25
#define BTSPELLTYPE_HEAL            0
#define BTSPELLTYPE_RESURRECT       1
#define BTSPELLTYPE_CUREPOISON      2
#define BTSPELLTYPE_CUREINSANITY    3
#define BTSPELLTYPE_YOUTH           4
#define BTSPELLTYPE_DISPOSSESS      5
#define BTSPELLTYPE_STONETOFLESH    6
#define BTSPELLTYPE_CUREPARALYZE    7
#define BTSPELLTYPE_RESTORELEVELS   8
#define BTSPELLTYPE_DAMAGE          9
#define BTSPELLTYPE_KILL            10
#define BTSPELLTYPE_POISON          11
#define BTSPELLTYPE_CAUSEINSANITY   12
#define BTSPELLTYPE_AGE             13
#define BTSPELLTYPE_POSSESS         14
#define BTSPELLTYPE_FLESHTOSTONE    15
#define BTSPELLTYPE_PARALYZE        16
#define BTSPELLTYPE_DRAINLEVEL      17
#define BTSPELLTYPE_SUMMONMONSTER   18
#define BTSPELLTYPE_SUMMONILLUSION  19
#define BTSPELLTYPE_DISPELLILLUSION 20
#define BTSPELLTYPE_SCRYSIGHT       21
#define BTSPELLTYPE_LIGHT           22
#define BTSPELLTYPE_ARMORBONUS      23
#define BTSPELLTYPE_HITBONUS        24
#define BTSPELLTYPE_TRAPDESTROY     25
#define BTSPELLTYPE_DOORDETECT      26
#define BTSPELLTYPE_PHASEDOOR       27
#define BTSPELLTYPE_DISPELLMAGIC    28
#define BTSPELLTYPE_REGENBARD       29
#define BTSPELLTYPE_DAMAGEBYLEVEL   30
#define BTSPELLTYPE_COMPASS         31
#define BTSPELLTYPE_PUSH            32
#define BTSPELLTYPE_ATTACKRATEBONUS 33
#define BTSPELLTYPE_REGENMANA       34
#define BTSPELLTYPE_SAVEBONUS       35
#define BTSPELLTYPE_BLOCKENCOUNTERS 36
#define BTSPELLTYPE_BLOCKMAGIC      37
#define BTSPELLTYPE_SPELLBIND       38
#define BTSPELLTYPE_LEVITATION      39
#define BTSPELLTYPE_REGENSKILL      40
#define BTSPELLTYPE_CURESTATUS      41
extern char *spellTypes[];
extern ArrayLookup spellTypeLookup;

#define BT_EFFECTIVERANGES 2
extern char *effectiveRanges[];

#define BT_AREAEFFECT 4
#define BTAREAEFFECT_NONE  0
#define BTAREAEFFECT_FOE   1
#define BTAREAEFFECT_GROUP 2
#define BTAREAEFFECT_ALL   3
extern char *areaEffect[];
extern ArrayLookup areaLookup;

#define BT_DURATION 6
#define BTDURATION_ONE        0
#define BTDURATION_SHORT      1
#define BTDURATION_MEDIUM     2
#define BTDURATION_LONG       3
#define BTDURATION_COMBAT     4
#define BTDURATION_PERMANENT  5
#define BTDURATION_CONTINUOUS 6
#define BTDURATION_INDEFINITE 7
extern char *durations[];
extern ArrayLookup durationLookup;

#define BT_MONSTEREXTRADAMAGE 11
#define BTEXTRADAMAGE_NONE        0
#define BTEXTRADAMAGE_POISON      1
#define BTEXTRADAMAGE_LEVELDRAIN  2
#define BTEXTRADAMAGE_INSANITY    3
#define BTEXTRADAMAGE_AGED        4
#define BTEXTRADAMAGE_POSSESSION  5
#define BTEXTRADAMAGE_STONED      6
#define BTEXTRADAMAGE_PARALYSIS   7
#define BTEXTRADAMAGE_CRITICALHIT 8
#define BTEXTRADAMAGE_ITEMZOT     9
#define BTEXTRADAMAGE_POINTPHAZE 10
extern char *extraDamage[];
extern ArrayLookup extraDamageLookup;

#define BT_RANGEDTYPES 4
#define BTRANGEDTYPE_NONE  0
#define BTRANGEDTYPE_FOE   1
#define BTRANGEDTYPE_GROUP 2
#define BTRANGEDTYPE_MAGIC 3
extern char *rangedTypes[];
extern ArrayLookup rangedTypeLookup;

#define BT_COMBATACTIONS 6
#define BTCOMBATACTION_ATTACK          0
#define BTCOMBATACTION_MOVEANDATTACK   1
#define BTCOMBATACTION_DEPENDENTATTACK 2
#define BTCOMBATACTION_SPECIALATTACK   3
#define BTCOMBATACTION_RANDOM          4
#define BTCOMBATACTION_NOTHING         5
extern char *combatActions[];
extern ArrayLookup combatActionLookup;

#define BT_ITEMTYPES 13
#define BTITEM_HANDWEAPON   1
#define BTITEM_INSTRUMENT   6
#define BTITEM_BOW          10
#define BTITEM_ARROW        11
#define BTITEM_THROWNWEAPON 12
extern char *itemTypes[];
extern ArrayLookup itemTypesLookup;

#define BTITEMCAST_NONE -1

#define BTTIMESUSABLE_UNLIMITED 255

#define BT_CONDITIONALCOMMANDS 19
#define BTCONDITION_ANYONEITEM      0
#define BTCONDITION_EVERYONEITEM    1
#define BTCONDITION_LASTINPUT       2
#define BTCONDITION_ANSWERYES       3
#define BTCONDITION_LOCALFLAGSET    4
#define BTCONDITION_LOCALFLAGCLEAR  5
#define BTCONDITION_GROUPFACING     6
#define BTCONDITION_MONSTERINPARTY  7
#define BTCONDITION_JOBINPARTY      8
#define BTCONDITION_DAYTIME         9
#define BTCONDITION_COUNTERGREATER  10
#define BTCONDITION_COUNTEREQUAL    11
#define BTCONDITION_COMBATWON       12
#define BTCONDITION_GLOBALFLAGSET   13
#define BTCONDITION_GLOBALFLAGCLEAR 14
#define BTCONDITION_RANDOM          15
#define BTCONDITION_RACEINPARTY     16
#define BTCONDITION_CANTAKEGOLD     17
#define BTCONDITION_EFFECTACTIVE    18
extern char *conditionalCommands[];

#define BT_SPECIALCOMMANDS 62
#define BTSPECIALCOMMAND_NOTHING          0
#define BTSPECIALCOMMAND_STOP             1
#define BTSPECIALCOMMAND_SPIN             2
#define BTSPECIALCOMMAND_DARKNESS         3
#define BTSPECIALCOMMAND_SILENCE          4
#define BTSPECIALCOMMAND_ANTIMAGIC        5
#define BTSPECIALCOMMAND_GETINPUT         6
#define BTSPECIALCOMMAND_SETLOCALFLAG     7
#define BTSPECIALCOMMAND_CLEARLOCALFLAG   8
#define BTSPECIALCOMMAND_TAKEITEM         9
#define BTSPECIALCOMMAND_GIVEITEM         10
#define BTSPECIALCOMMAND_SELLITEM         11
#define BTSPECIALCOMMAND_CASTSPELL        12
#define BTSPECIALCOMMAND_PRINT            13
#define BTSPECIALCOMMAND_REGENERATESPELLS 14
#define BTSPECIALCOMMAND_TAKESPELLS       15
#define BTSPECIALCOMMAND_HEALHITPOINTS    16
#define BTSPECIALCOMMAND_DAMAGEHITPOINTS  17
#define BTSPECIALCOMMAND_REGENERATESONGS  18
#define BTSPECIALCOMMAND_TAKESONGS        19
#define BTSPECIALCOMMAND_BACKONE          20
#define BTSPECIALCOMMAND_FORWARDONE       21
#define BTSPECIALCOMMAND_TELEPORT         22
#define BTSPECIALCOMMAND_GUILD            23
#define BTSPECIALCOMMAND_REVIEW           24
#define BTSPECIALCOMMAND_SHOP             25
#define BTSPECIALCOMMAND_TRAP             26
#define BTSPECIALCOMMAND_DRAWPICTURE      27
#define BTSPECIALCOMMAND_CLEARSPECIALAT   28
#define BTSPECIALCOMMAND_SETSPECIALAT     29
#define BTSPECIALCOMMAND_PRINTLABEL       30
#define BTSPECIALCOMMAND_MONSTERJOIN      31
#define BTSPECIALCOMMAND_ALLMONSTERSLEAVE 32
#define BTSPECIALCOMMAND_ALLMONSTERSHOSTILE 33
#define BTSPECIALCOMMAND_PLAYSOUND        34
#define BTSPECIALCOMMAND_SETCOUNTER       35
#define BTSPECIALCOMMAND_ADDCOUNTER       36
#define BTSPECIALCOMMAND_SETENCOUNTER     37
#define BTSPECIALCOMMAND_SETNUMENCOUNTER  38
#define BTSPECIALCOMMAND_BEGINCOMBAT      39
#define BTSPECIALCOMMAND_CHEST            40
#define BTSPECIALCOMMAND_SETGLOBALFLAG    41
#define BTSPECIALCOMMAND_CLEARGLOBALFLAG  42
#define BTSPECIALCOMMAND_GIVEGOLD         43
#define BTSPECIALCOMMAND_GIVEXP           44
#define BTSPECIALCOMMAND_PRESSANYKEY      45
#define BTSPECIALCOMMAND_MONSTERLEAVE     46
#define BTSPECIALCOMMAND_MONSTERHOSTILE   47
#define BTSPECIALCOMMAND_SETDIRECTION     48
#define BTSPECIALCOMMAND_CLEARSPECIAL     49
#define BTSPECIALCOMMAND_SETSPECIAL       50
#define BTSPECIALCOMMAND_RANDOMENCOUNTER  51
#define BTSPECIALCOMMAND_CLEARTEXT        52
#define BTSPECIALCOMMAND_TAKEGOLD         53
#define BTSPECIALCOMMAND_DRAWFULLPICTURE  54
#define BTSPECIALCOMMAND_SETTIMESPECIAL   55
#define BTSPECIALCOMMAND_CLEARTIMESPECIAL 56
#define BTSPECIALCOMMAND_GOTO             57
#define BTSPECIALCOMMAND_SUBTRACTCOUNTER  58
#define BTSPECIALCOMMAND_TELEPORTRELATIVE 59
#define BTSPECIALCOMMAND_TELEACTIVATE     60
#define BTSPECIALCOMMAND_LABEL            61
extern char *specialCommands[];

#define BTSPECIAL_NONE -1

#define BT_SPECIALFLAGS 3
#define BTSPECIALFLAG_SILENCE   0
#define BTSPECIALFLAG_ANTIMAGIC 1
#define BTSPECIALFLAG_DARKNESS  2
extern char *specialFlag[];
extern ArrayLookup specialFlagLookup;

#define BT_DIRECTIONS 4
#define BTDIRECTION_NORTH 0
#define BTDIRECTION_EAST  1
#define BTDIRECTION_SOUTH 2
#define BTDIRECTION_WEST  3
extern char *directions[];
extern ArrayLookup directionsLookup;

#define BTMAPTYPE_CITY       2
#define BTMAPTYPE_WILDERNESS 3

#define BT_STATS 5
#define BTSTAT_MAX 18
#define BTSTAT_ST 0
#define BTSTAT_IQ 1
#define BTSTAT_DX 2
#define BTSTAT_CN 3
#define BTSTAT_LK 4
extern char *statAbbrev[];
extern ArrayLookup statLookup;

#define BT_GENDERS 3
#define BTGENDER_MALE   0
#define BTGENDER_FEMALE 1
#define BTGENDER_IT     2
extern char *genderNames[];
extern ArrayLookup genderLookup;
extern char *genderPronouns[];

#define BTSP_REGEN 50

#define BTJOB_MONSTER  11
#define BTJOB_ILLUSION 12

#define BTMONSTER_NONE -1

#define BT_ITEMS (BTGame::getGame()->getModule()->maxItems)
#define BT_PARTYSIZE 7
#define BTPARTY_REMOVE -1
#define BT_BACK 4

#define BTITEM_NONE 0x4000

#define BTITEMCOUNT_UNLIMITED -1
#define BTITEMCOUNT_MAX 9999

#define BTITEM_CANNOTEQUIP 0
#define BTITEM_NOTEQUIPPED 1
#define BTITEM_EQUIPPED    2

#define BTSAVE_DIFFICULTY 20

#define BTSKILL_DEFAULTDIFFICULTY -1

#define BTSTATUS_LEVELDRAIN -2
#define BTSTATUS_NONE       -1
#define BTSTATUS_DEAD       0
#define BTSTATUS_POISONED   1
#define BTSTATUS_INSANE     2
#define BTSTATUS_AGED       3
#define BTSTATUS_POSSESSED  4
#define BTSTATUS_STONED     5
#define BTSTATUS_PARALYZED  6
#define BTSTATUS_NPC        7
extern PairLookup statusLookup;

#define BTCOMBAT_MAXENCOUNTERS 4

#define BTTARGET_INDIVIDUAL  0x0FFF
#define BTTARGET_NOSINGER    0x0FFF
#define BTTARGET_GROUPSHIFT  24
#define BTTARGET_NONE        0
#define BTTARGET_PARTY       1
#define BTTARGET_MONSTER     2
#define BTTARGET_ALLMONSTERS 7

#define BTMUSICID_NONE -1

#define BTTIME_MAXDAYS    256
#define BTTIME_PERMANENT  0x08000000U
#define BTTIME_CONTINUOUS 0x04000000U
#define BTTIME_INDEFINITE 0x02000000U
#define BTTIME_COMBAT     0x01000000U
#define BTTIME_MAP        0x10000000U

#define BTTIME_ONETURN 6000 /*ms*/
#define BTTIME_MINUTE ((60 /*sec*/ * 1000 /*ms/sec*/) / BTTIME_ONETURN)

#define BTDISTANCE_MAX 9

#define BT_RESTRICTIONS 3
#define BTRESTRICTION_NONE      0
#define BTRESTRICTION_COMBAT    1
#define BTRESTRICTION_NONCOMBAT 2
extern char *restriction[];
extern ArrayLookup restrictionLookup;

#define BT_TARGETOVERRIDES 3
#define BTTARGETOVERRIDE_NONE        0
#define BTTARGETOVERRIDE_SINGER      1
#define BTTARGETOVERRIDE_ALLMONSTERS 2
extern char *targetOverride[];
extern ArrayLookup targetOverrideLookup;

#define BT_MAPDISPLAYMODES 3
#define BTMAPDISPLAYMODE_REQUEST 0
#define BTMAPDISPLAYMODE_NO3D    1
#define BTMAPDISPLAYMODE_ALWAYS  2
extern char *mapDisplayMode[];
extern ArrayLookup mapDisplayModeLookup;

#define BTKNOWLEDGE_NO   0
#define BTKNOWLEDGE_YES  1
#define BTKNOWLEDGE_FULL 2

#define BTINITIATIVE_INACTIVE -99
#define BTINITIATIVE_ACTIVE 0

#endif

