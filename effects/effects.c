//
// Created by César on 16/05/2022.
//
#include "effects.h"

struct effects_ {
    int type; // 1=damage, 2=fire, 3=dodge, 4=weakness, 5=slowness, 6=strength, 7=dexterity
    int value; // power, turn...
};
typedef struct effects_ * effects;

effects newEffect(int type, int value) {

    effects new = (effects)malloc(sizeof(struct effects_));
    new->type=type;
    new->value=value;

    return new;
}

void damage(int value, monster monster)
{
    if (monster==NULL)
        currentPlayerHP-=value;
    if (monster)
        monster->hp-=value;
}

void fire(int value, monster monster)
{
    if (monster==NULL)
        playerFire=value;
    if (monster)
        monster->fire=value;
}

void dodge(int value, monster monster)
{
    if (monster==NULL)
        playerDodge=value;
    if (monster)
        monster->dodge=value;
}

void weakness(int value, monster monster)
{
    if (monster==NULL)
        playerWeak=value;
    if (monster)
        monster->weak=value;
}

void slowness(int value, monster monster)
{
    if (monster==NULL)
        playerSlow=value;
    if (monster)
        monster->slow=value;
}

void strength(int value, monster monster)
{
    if (monster==NULL)
        playerStrength+=value;
    if (monster)
        monster->strength+=value;
}

void dexterity(int value, monster monster)
{
    if (monster==NULL)
        playerDexterity+=value;
    if (monster)
        monster->dexterity+=value;
}

void casseCroute(int value)
{
    currentPlayerHP+=value;
}

void strengthDef(int value)
{
    playerStrength+=value;
}

void dexterityDef(int value)
{
    playerDexterity+=value;
}

void powerMax(int value)
{
    maxPlayerEnergy+=value;
}

void HPMax(int value)
{
    maxPlayerHP+=value;
}