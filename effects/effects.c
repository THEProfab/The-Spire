//
// Created by César on 16/05/2022.
//
#include <bool.h>
#include "effects.h"

struct effects_ {
    int type; // 1=damage, 2=fire, 3=dodge, 4=weakness, 5=slowness, 6=strength, 7=dexterity, 8=Abyssal
    int value; // power, turn...
    monster monster; // monster, NULL
};

effect newEffect(int type, int value) {

    effects new = malloc(sizeof(effects_));
    new->type=type;
    new->value=value;
    new->monster=NULL;

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
        monster->hp=value;
}

void dodge(int value, monster monster)
{
    if (monster==NULL)
        playerDodge=value;
    if (monster)
        monster->doge=value;
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
        playerStrength=value;
    if (monster)
        monster->strength=value;
}

void dexterity(int value, monster monster)
{
    if (monster==NULL)
        playerDexterity=value;
    if (monster)
        monster->dexterity=value;
}