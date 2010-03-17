#ifndef __MANIFEST_H
#define __MANIFEST_H
/*-------------------------------------------------------------------------*\
  <manifest.h> -- Manifest header file

  Date      Programmer  Description
  03/14/10  Dennis      Created.
\*-------------------------------------------------------------------------*/

#include "btconst.h"
#include "dice.h"
#include "spelleffect.h"
#include "xmlserializer.h"

class BTManifest : public XMLObject
{
 public:
  BTManifest() : type(-1) {}

  virtual std::list<BTBaseEffect*> manifest(BTDisplay &d, bool partySpell, BTCombat *combat, unsigned int expire, int casterLevel, int distance, int group, int target, bool song);
  virtual void serialize(ObjectSerializer *s);

  static XMLObject *create(const XML_Char *name, const XML_Char **atts) { return new BTManifest; }

  int type;
};

class BTMultiManifest : public BTManifest
{
 public:
  BTMultiManifest() : restriction(BTRESTRICTION_NONE) {}

  virtual std::list<BTBaseEffect*> manifest(BTDisplay &d, bool partySpell, BTCombat *combat, unsigned int expire, int casterLevel, int distance, int group, int target, bool song);
  virtual void serialize(ObjectSerializer *s);

  static XMLObject *create(const XML_Char *name, const XML_Char **atts) { return new BTMultiManifest; }

  int restriction;
  XMLVector<BTManifest*> content;
};

#endif
