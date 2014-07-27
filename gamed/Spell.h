#ifndef _SPELL_H
#define _SPELL_H

#include "stdafx.h"
#include "Projectile.h"

class Unit;
class Champion;

enum SpellState {
   STATE_READY,
   STATE_CASTING,
   STATE_COOLDOWN
};

class Spell {
   
public:
   Spell(uint32 id, Champion* owner, float castTime, uint8 slot) : id(id), owner(owner), level(0), slot(slot), state(STATE_READY), castTime(castTime), currentCooldown(0), currentCastTime(0) { }
   
   /**
    * Called when the character casts the spell
    */
   virtual bool cast(float x, float y, Unit* u = 0);
      
   /**
    * Called every diff milliseconds to update the spell
    */
   virtual void update(unsigned int diff);
   
   /**
    * Called by projectiles when they land / hit
    * In here we apply the effects : damage, buffs, debuffs...
    */
   virtual void applyEffects(glm::vec2 t, Projectile* p = 0) = 0;
   
   Champion* getOwner() const { return owner; }
   
   /**
    * @return Spell's unique ID
    */
   uint32 getId() const { return id; }
   float getCastTime() const { return castTime; }
   
   /**
    * TODO : Add in CDR % from champion's stat
    */
   float getCooldown() const {       
      if(level>=5|| level < 0) {
         return 0;
      }
      return cooldown[level-1];
   }

   void setCooldown(int level, int value)
   {
	   if(level>=5|| level < 0)
		   return;

	   cooldown[level-1] = value;
   }
   
   /**
    * @return the mana/energy/health cost
    */
   float getCost() const {
      if(!level) {
         return 0;
      }
      return cost[level-1];
   }
   
   uint8 getLevel() const {
      return level;
   }
   
   virtual void levelUp() {
      ++level;
   }
   
   SpellState getState() const {
      return state;
   }
   
   uint8 getSlot() const {
      return slot;
   }

protected:
	uint32 id;
	Champion* owner;
	uint8 level;
	uint8 slot;
	SpellState state;

	float castTime;
	float cooldown[5];
	float cost[5];

	float currentCooldown;
	float currentCastTime;

	Unit* target;
	float x, y;
};

#endif