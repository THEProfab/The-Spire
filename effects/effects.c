//
// Created by César on 16/05/2022.
//
#include "effects.h"

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
        currentPlayerDodge=value;
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

void sandwich()
{
    if (currentPlayerHP < maxPlayerHP){
        printf("Peter récupère 6 hp grâce au casse-croûte !\n");
        int testSustain = (currentPlayerHP + 6)%maxPlayerHP; // test pour voir si on dépasse le max d'hp
        if (testSustain>=1 && testSustain<=5){
            currentPlayerHP += 6-testSustain;
        } else {
            currentPlayerHP += 6;
        }
    }
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

void mana(int value)
{
    if (maxPlayerMana<=currentPlayerMana+value)
        currentPlayerMana+=value;
    else
        currentPlayerMana=maxPlayerMana;
}