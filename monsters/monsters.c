#include <stdio.h>
#include <stdlib.h>
#include "monsters.h"

//First half monsters
monster createJawurm1() {
    monster newMonster = (monster) malloc(sizeof(struct monster_));
    int lowerHp = 40;
    int upperHp = 44;
    newMonster->id = 0;
    newMonster->hp = (rand() % (upperHp - lowerHp + 1)) + lowerHp;
    newMonster->name = "Jawurm";
    newMonster->dodge = 0;
    newMonster->strength = 0;
    newMonster->dexterity = 0;
    newMonster->fire = 0;
    newMonster->weak = 0;
    newMonster->slow = 0;
    return newMonster;
}

/**
 * Randomly casts a Jawurm's ability
 * @param jawurm user/target monster
 * @param randomValue corresponding to the ability
*/
void jawurm1Abilities(monster jawurm, int randomValue) {
    if (randomValue == 0) {
        damage(11, NULL);
    } else if (randomValue == 1) {
        damage(7, NULL);
        dodge(5, jawurm);
    } else if (randomValue == 2) {
        strength(3, jawurm);
        dodge(6, jawurm);
    }
}

/**
 * Announce the next ability the Jawurm will use
 * @param randomValue corresponding to the ability
 */
void announceAbilityJawurm1(int randomValue) {
    if (randomValue == 0) {
        printf("Degats : 11\n");
    } else if (randomValue == 1) {
        printf("Degats : 7, Esquive : 5\n");
    } else if (randomValue == 2) {
        printf("Force : 3, Esquive : 6\n");
    }
}

monster createBlouni() {
    monster newMonster = (monster) malloc(sizeof(struct monster_));
    int lowerHp = 46;
    int upperHp = 50;
    newMonster->id = 1;
    newMonster->hp = (rand() % (upperHp - lowerHp + 1)) + lowerHp;
    newMonster->name = "Blouni";
    newMonster->dodge = 0;
    newMonster->strength = 0;
    newMonster->dexterity = 0;
    newMonster->fire = 0;
    newMonster->weak = 0;
    newMonster->slow = 0;
    return newMonster;
}

/**
 * Randomly casts a Blouni's ability
 * @param blouni user/target monster
 * @param randomValue corresponding to the ability
 */
void blouniAbilities(monster blouni, int randomValue) {
    if (randomValue == 0) {
        damage(13, NULL);
    } else if (randomValue == 1) {
        damage(8, NULL);
        weakness(2, NULL);
    }
}

/**
 * Announce the next ability the Blouni will use
 * @param randomValue corresponding to the ability
 */
void announceAbilityBlouni(int randomValue) {
    if (randomValue == 0) {
        printf("Degats : 13\n");
    } else if (randomValue == 1) {
        printf("Degats : 8, Faiblesse : 2\n");
    }
}

monster createKeliko() {
    monster newMonster = (monster) malloc(sizeof(struct monster_));
    int lowerHp = 60;
    int upperHp = 70;
    newMonster->id = 2;
    newMonster->hp = (rand() % (upperHp - lowerHp + 1)) + lowerHp;
    newMonster->name = "Keliko";
    newMonster->dodge = 0;
    newMonster->strength = 0;
    newMonster->dexterity = 0;
    newMonster->fire = 0;
    newMonster->weak = 0;
    newMonster->slow = 0;
    return newMonster;
}

/**
 * Randomly casts a Keliko's ability
 * @param keliko user/target monster
 * @param randomValue corresponding to the ability
 */
void kelikoAbilities(monster keliko, int randomValue) {
    if (randomValue == 0) {
        damage(3, NULL);
        dodge(3, keliko);
        strength(2, keliko);
    } else if (randomValue == 1) {
        damage(3, NULL);
        dodge(3, keliko);
        dexterity(2, keliko);
    }
}

/**
 * Announce the next ability the Keliko will use
 * @param randomValue corresponding to the ability
 */
void announceAbilityKeliko(int randomValue) {
    if (randomValue == 0) {
        printf("Degats : 3, Esquive : 3, Force : 3\n");
    } else if (randomValue == 1) {
        printf("Degats : 3, Esquive : 3, Dexterite : 3\n");
    }
}

//Second half monsters
monster createJawurm2() {
    monster newMonster = (monster) malloc(sizeof(struct monster_));
    int lowerHp = 55;
    int upperHp = 62;
    newMonster->id = 3;
    newMonster->hp = (rand() % (upperHp - lowerHp + 1)) + lowerHp;
    newMonster->name = "Jawurm";
    newMonster->dodge = 0;
    newMonster->strength = 0;
    newMonster->dexterity = 0;
    newMonster->fire = 0;
    newMonster->weak = 0;
    newMonster->slow = 0;
    return newMonster;
}

/**
 * Randomly casts a Jawurm's ability
 * @param jawurm user/target monster
 * @param randomValue corresponding to the ability
 */
void jawurm2Abilities(monster jawurm, int randomValue) {
    if (randomValue == 0) {
        damage(15, NULL);
    } else if (randomValue == 1) {
        damage(12, NULL);
        dodge(10, jawurm);
    } else if (randomValue == 2) {
        strength(3, jawurm);
        dodge(18, jawurm);
    }
}

/**
 * Announce the next ability the Jawurm will use
 * @param randomValue corresponding to the ability
 */
void announceAbilityJawurm2(int randomValue) {
    if (randomValue == 0) {
        printf("Degats : 15\n");
    } else if (randomValue == 1) {
        printf("Degats : 12, Esquive : 10\n");
    } else if (randomValue == 2) {
        printf("Force : 3, Esquive : 18\n");
    }
}

monster createRedoni() {
    monster newMonster = (monster) malloc(sizeof(struct monster_));
    int lowerHp = 50;
    int upperHp = 54;
    newMonster->id = 4;
    newMonster->hp = (rand() % (upperHp - lowerHp + 1)) + lowerHp;
    newMonster->name = "Redoni";
    newMonster->dodge = 0;
    newMonster->strength = 0;
    newMonster->dexterity = 0;
    newMonster->fire = 0;
    newMonster->weak = 0;
    newMonster->slow = 0;
    return newMonster;
}

/**
 * Randomly casts a Redoni's ability
 * @param redoni user/target monster
 * @param randomValue corresponding to the ability
 */
void redoniAbilities(monster redoni, int randomValue) {
    if (randomValue == 0) {
        damage(20, NULL);
    } else if (randomValue == 1) {
        damage(15, NULL);
        weakness(2, NULL);
    }
}

/**
 * Announce the next ability the Redoni will use
 * @param randomValue corresponding to the ability
 */
void announceAbilityRedoni(int randomValue) {
    if (randomValue == 0) {
        printf("Degats : 20\n");
    } else if (randomValue == 1) {
        printf("Degats : 15, Faiblesse : 2\n");
    }
}

monster createMangoustine() {
    monster newMonster = (monster) malloc(sizeof(struct monster_));
    int lowerHp = 70;
    int upperHp = 80;
    newMonster->id = 5;
    newMonster->hp = (rand() % (upperHp - lowerHp + 1)) + lowerHp;
    newMonster->name = "Mangoustine";
    newMonster->dodge = 0;
    newMonster->strength = 0;
    newMonster->dexterity = 0;
    newMonster->fire = 0;
    newMonster->weak = 0;
    newMonster->slow = 0;
    return newMonster;
}

/**
 * Randomly casts a Mangounstine's ability
 * @param mangoustine user/target monster
 * @param randomValue corresponding to the ability
 */
void mangoustineAbilities(monster mangoustine) {
    damage(3, NULL);
    dodge(3, mangoustine);
    strength(2, mangoustine);
    dexterity(2, mangoustine);
}

/**
 * Announce the next ability the Mangoustine will use
 * @param randomValue corresponding to the ability
 */
void announceAbilityMangoustine(int randomValue) {
    printf("Degats : 3, Esquive : 3, Force : 2, Dexterite : 2\n");
}

//Minibosses
monster createEldan() {
    monster newMonster = (monster) malloc(sizeof(struct monster_));
    newMonster->id = 6;
    newMonster->hp = 80;
    newMonster->name = "Eldan";
    newMonster->dodge = 0;
    newMonster->strength = 0;
    newMonster->dexterity = 0;
    newMonster->fire = 0;
    newMonster->weak = 0;
    newMonster->slow = 0;
    return newMonster;
}

/**
 * Randomly casts an Eldan's ability
 * @param eldan user/target monster
 * @param randomValue corresponding to the ability
 */
void eldanAbilities(monster eldan, int randomValue) {
    if (randomValue == 0) {
        damage(15, NULL);
    } else if (randomValue == 1) {
        damage(10, NULL);
        dodge(15, eldan);
    } else if (randomValue == 2) {
        weakness(2, NULL);
        slowness(2, NULL);
        strength(-1, NULL);
        dexterity(-1, NULL);
    }
}

/**
 * Announce the next ability the Eldan will use
 * @param randomValue corresponding to the ability
 */
void announceAbilityEldan(int randomValue) {
    if (randomValue == 0) {
        printf("Degats : 15\n");
    } else if (randomValue == 1) {
        printf("Degats : 10, Esquive : 15\n");
    } else if (randomValue == 2) {
        printf("Faiblesse : 2, Lenteur : 2, Force : -1, Dexterite : -1\n");
    }
}

monster createPyrox() {
    monster newMonster = (monster) malloc(sizeof(struct monster_));
    newMonster->id = 7;
    newMonster->hp = 120;
    newMonster->name = "Pyrox";
    newMonster->dodge = 0;
    newMonster->strength = 0;
    newMonster->dexterity = 0;
    newMonster->fire = 0;
    newMonster->weak = 0;
    newMonster->slow = 0;
    return newMonster;
}

/**
 * Randomly casts a Pyrox's ability
 * @param pyrox user/target monster
 * @param randomValue corresponding to the ability
 */
void pyroxAbilities(monster pyrox, int randomValue) {
    if (randomValue == 0) {
        fire(5, NULL);
        dodge(10, pyrox);
    } else if (randomValue == 1) {
        fire(10, NULL);
        dexterity(2, pyrox);
    }
}

/**
 * Announce the next ability the Pyrox will use
 * @param randomValue corresponding to the ability
 */
void announceAbilityPyrox(int randomValue) {
    if (randomValue == 0) {
        printf("Feu : 5, Esquive : 10\n");
    } else if (randomValue == 1) {
        printf("Feu : 10, Dexterite : 2\n");
    }
}

//Boss
monster createKeeperOfTheFeather() {
    monster newMonster = (monster) malloc(sizeof(struct monster_));
    newMonster->id = 8;
    newMonster->hp = 150;
    newMonster->name = "Keeper of the Feather";
    newMonster->dodge = 0;
    newMonster->strength = 0;
    newMonster->dexterity = 0;
    newMonster->fire = 0;
    newMonster->weak = 0;
    newMonster->slow = 0;
    return newMonster;
}

/**
 * Randomly casts a Keeper of the Feather's ability
 * @param keeperOfTheFeather user/target monster
 * @param randomValue corresponding to the ability
 */
void keeperOfTheFeatherAbilities(monster keeperOfTheFeather, int randomValue) {
    if (randomValue == 0) {
        fire(3, NULL);
        damage(6, NULL);
        strength(1, keeperOfTheFeather);
        slowness(1, NULL);
        weakness(1, NULL);
        dexterity(1, keeperOfTheFeather);
        dodge(5, keeperOfTheFeather);
    } else if (randomValue == 1) {
        damage(30, NULL);
    } else if (randomValue == 2) {
        damage(4, NULL);
        damage(4, NULL);
        damage(4, NULL);
        damage(4, NULL);
        damage(4, NULL);
    } else if (randomValue == 3) {
    }
}

/**
 * Announce the next ability the Keeper of the Feather will use
 * @param randomValue corresponding to the ability
 */
void announceAbilityKeeperOfTheFeather(int randomValue) {
    if (randomValue == 0) {
        printf("Feu : 3, Degats : 6, Force : 1, Lenteur : 1, Faiblesse : 1, Dexterite : 1, Esquive : 5\n");
    } else if (randomValue == 1) {
        printf("Degats : 30\n");
    } else if (randomValue == 2) {
        printf("5 x Dégats : 4\n");
    }
}



//First half monsters array
monster (*monsterArrayFirstHalf[3])() = {createJawurm1, createBlouni, createKeliko};

//Second half monsters array
monster (*monsterArraySecondHalf[3])() = {createJawurm2, createRedoni, createMangoustine};

//Miniboss array
monster (*miniBossArray[2])() = {createEldan, createPyrox};

/**
 * Pick a random monster from the first half
 * @return a monster from the array (jawurm1, blouni or keliko)
 */
monster pickAMonster13() {
    int randomVariable = (int) rand() % 3;
    return monsterArrayFirstHalf[randomVariable]();
}

/**
 * Pick a random monster from the second half
 * @return a monster from the array (jawurm2, redoni or mangoustine)
 */
monster pickAMonster59() {
    int randomVariable = (int) rand() % 3;
    return monsterArraySecondHalf[randomVariable]();
}

/**
 * Pick a random miniboss
 * @return a miniboss from the array (eldan or pyrox)
 */
monster pickAMiniBoss() {
    int randomVariable = (int) rand() % 2;
    return miniBossArray[randomVariable]();
}