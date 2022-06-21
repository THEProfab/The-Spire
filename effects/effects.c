//
// Created by César on 16/05/2022.
//
#include "effects.h"

/**
 * create a new effect
 * @param type
 * @param value
 * @return
 */
effects newEffect(int type, int value) {

    effects new = (effects) malloc(sizeof(struct effects_));
    new->type = type;
    new->value = value;

    return new;
}

/**
 * apply damage effect
 * @param value
 * @param monster
 */
void damage(int value, monster monster) {
    if (monster == NULL)
        currentPlayerHP -= value;
    if (monster)
        monster->hp -= value;
}

/**
 * apply fire effect
 * @param value
 * @param monster
 */
void fire(int value, monster monster) {
    if (monster == NULL)
        playerFire = value;
    if (monster)
        monster->fire = value;
}

/**
 * apply dodge effect
 * @param value
 * @param monster
 */
void dodge(int value, monster monster) {
    if (monster == NULL)
        currentPlayerDodge = value;
    if (monster)
        monster->dodge = value;
}

/**
 * apply weakness effect
 * @param value
 * @param monster
 */
void weakness(int value, monster monster) {
    if (monster == NULL)
        playerWeak = value;
    if (monster)
        monster->weak = value;
}

/**
 * apply slowness effect
 * @param value
 * @param monster
 */
void slowness(int value, monster monster) {
    if (monster == NULL)
        playerSlow = value;
    if (monster)
        monster->slow = value;
}

/**
 * apply strength effect
 * @param value
 * @param monster
 */
void strength(int value, monster monster) {
    if (monster == NULL)
        playerStrength += value;
    if (monster)
        monster->strength += value;
}

/**
 * apply dexterity effect
 * @param value
 * @param monster
 */
void dexterity(int value, monster monster) {
    if (monster == NULL)
        playerDexterity += value;
    if (monster)
        monster->dexterity += value;
}

/**
 * returns mana
 * @param value
 * @param monster
 */
void mana(int value) {
    if (maxPlayerMana <= currentPlayerMana + value)
        currentPlayerMana += value;
    else
        currentPlayerMana = maxPlayerMana;
}

/**
 * apply the sandwich effect
 * @param value
 * @param monster
 */
void sandwich(int value) {
    currentPlayerHP += value;
}

/**
 * apply the sword effect
 * @param value
 * @param monster
 */
void strengthDef(int value) {
    playerStrength += value;
}

/**
 * apply the helmet effect
 * @param value
 * @param monster
 */
void dexterityDef(int value) {
    playerDexterity += value;
}

/**
 * apply shoes effect
 * @param value
 * @param monster
 */
void powerMax(int value) {
    maxPlayerEnergy += value;
}

/**
 * apply the armor effect
 * @param value
 * @param monster
 */
void HPMax(int value) {
    maxPlayerHP += value;
}