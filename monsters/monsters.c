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

void jawurm1Abilities(monster jawurm) {
    int randomValue = rand() % 3;
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

void blouniAbilities(monster blouni) {
    int randomValue = rand() % 2;
    if (randomValue == 0) {
        damage(13, NULL);
    } else if (randomValue == 1) {
        damage(8, NULL);
        weakness(2, NULL);
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

void kelikoAbilities(monster keliko) {
    int randomValue = rand() % 2;
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

void jawurm2Abilities(monster jawurm) {
    int randomValue = rand() % 3;
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

void redoniAbilities(monster redoni) {
    int randomValue = rand() % 2;
    if (randomValue == 0) {
        damage(20, NULL);
    } else if (randomValue == 1) {
        damage(15, NULL);
        weakness(2, NULL);
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

void mangoustineAbilities(monster mangoustine) {
    damage(3, NULL);
    dodge(3, mangoustine);
    strength(2, mangoustine);
    dexterity(2, mangoustine);
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

void eldanAbilities(monster eldan) {
    int randomValue = rand() % 3;
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

void pyroxAbilities(monster pyrox) {
    int randomValue = rand() % 2;
    if (randomValue == 0) {
        fire(5, NULL);
        dodge(10, pyrox);
    } else if (randomValue == 1) {
        fire(10, NULL);
        dexterity(2, pyrox);
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

void keeperOfTheFeatherAbilities(monster keeperOfTheFeather) {
    int randomValue = rand() % 4;
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

monster (*monsterArrayFirstHalf[3])() = {createJawurm1, createBlouni, createKeliko};

monster (*monsterArraySecondHalf[3])() = {createJawurm2, createRedoni, createMangoustine};

monster (*miniBossArray[2])() = {createEldan, createPyrox};

monster pickAMonster13() {
    int randomVariable = (int) rand() % 3;
    return monsterArrayFirstHalf[randomVariable]();
}

monster pickAMonster59() {
    int randomVariable = (int) rand() % 3;
    return monsterArraySecondHalf[randomVariable]();
}

monster pickAMiniBoss() {
    int randomVariable = (int) rand() % 2;
    return miniBossArray[randomVariable]();
}

void monsterMain() {
    monster jawurm = createJawurm1();
    printf("Jawurm name : %s \n", jawurm->name);
    printf("Jawurm id : %d \n", jawurm->id);
    printf("Jawurm hp : %d \n", jawurm->hp);
    printf("Jawurm strength : %d \n", jawurm->strength);
    printf("Jawurm dodge : %d \n", jawurm->dodge);
    printf("Jawurm dexterity : %d \n", jawurm->dexterity);
    printf("Jawurm fire : %d \n", jawurm->fire);
    printf("Jawurm slow : %d \n", jawurm->slow);
    printf("Jawurm weak : %d \n", jawurm->weak);


    monster blouni = createBlouni();
    printf("blouni name : %s \n", blouni->name);
    monster keliko = createKeliko();
    printf("keliko name : %s \n", keliko->name);
    monster jawurm2 = createJawurm2();
    printf("jawurm2 name : %s \n", jawurm2->name);
    monster redoni = createRedoni();
    printf("redoni name : %s \n", redoni->name);
    monster mangoustine = createMangoustine();
    printf("mangoustine name : %s \n", mangoustine->name);
    monster eldan = createEldan();
    printf("eldan name : %s \n", eldan->name);
    monster pyrox = createPyrox();
    printf("pyrox name : %s \n", pyrox->name);
    monster keeperOfTheFeather = createKeeperOfTheFeather();
    printf("KeeperOfTheFeather name : %s \n", keeperOfTheFeather->name);
}