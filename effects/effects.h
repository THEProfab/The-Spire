//
// Created by César on 16/05/2022.
//

#ifndef THE_SPIRE_EFFECTS_H
#define THE_SPIRE_EFFECTS_H

#include <stdlib.h>
#include "autre/monster.c"

struct effects_ ;
typedef struct effects_ * effects;

#endif //THE_SPIRE_EFFECTS_H


effects newEffect(int type, int value);
void damage(int value, monster monster);
void fire(int value, monster monster);
void dodge(int value, monster monster);
void weakness(int value, monster monster);
void slowness(int value, monster monster);
void strength(int value, monster monster);
void dexterity(int value, monster monster);
void casseCroute(int value);
void strengthDef(int value);
void dexterityDef(int value);
void powerMax(int value);
void HPMax(int value);