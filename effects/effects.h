//
// Created by César on 16/05/2022.
//

#ifndef THE_SPIRE_EFFECTS_H
#define THE_SPIRE_EFFECTS_H

#include <stdlib.h>
#include "../monsters/monsters.h"

struct effects_ {
    int type; // 1=damage, 2=fire, 3=dodge, 4=weakness, 5=slowness, 6=strength, 7=dexterity
    int value; // power, turn...
};
typedef struct effects_ * effects;

extern int currentPlayerHP;
extern int maxPlayerHP;
extern int currentPlayerDodge;
extern int currentPlayerEnergy;
extern int maxPlayerEnergy;
extern int currentPlayerMana;
extern int maxPlayerMana;
extern int playerStrength;
extern int playerDexterity;
extern int playerFire;
extern int playerWeak;
extern int playerSlow;
//item items[5];

effects newEffect(int type, int value);
void damage(int value, monster monster);
void fire(int value, monster monster);
void dodge(int value, monster monster);
void weakness(int value, monster monster);
void slowness(int value, monster monster);
void strength(int value, monster monster);
void dexterity(int value, monster monster);
void sandwich(int value);
void strengthDef(int value);
void dexterityDef(int value);
void powerMax(int value);
void HPMax(int value);

#endif //THE_SPIRE_EFFECTS_H