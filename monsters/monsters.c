#include <stdio.h>
#include <stdlib.h>
#include "monsters.h"

/**
 * Basic structure for monster
 */
struct monster_ {
    int id;
    int hp;
    char *name;

    int dodge; //Réduit de x les prochains dégâts reçus, remis à zéro à la fin du tour
    int strength; //Inflige des dégâts supplémentaires
    int dexterity; //Donne de l'esquive bonus
    int fire; //Valeur du feu, diminue de moitié à la fin du tour, inflige des dégâts à cette entité
    int weak; //Attaque diminuée de 25%, arrondi au supérieur, pour x tours
    int slow; //Esquive gagnée divisée par deux, diminue de 1 par tour

    //attack* attacks; //Le tableau d'attaques
};

typedef struct monster_ *monster;

//First half monsters
monster createJawurm1() {
    monster newMonster = (monster) malloc(sizeof(monster));
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

monster createBlouni() {
    monster newMonster = (monster) malloc(sizeof(monster));
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

monster createKeliko() {
    monster newMonster = (monster) malloc(sizeof(monster));
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

//Second half monsters
monster createJawurm2() {
    monster newMonster = (monster) malloc(sizeof(monster));
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

monster createRedoni() {
    monster newMonster = (monster) malloc(sizeof(monster));
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

monster createMangoustine() {
    monster newMonster = (monster) malloc(sizeof(monster));
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

//Minibosses
monster createEldan() {
    monster newMonster = (monster) malloc(sizeof(monster));
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

monster createPyrox() {
    monster newMonster = (monster) malloc(sizeof(monster));
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

//Boss
monster createKeeperOfTheFeather() {
    monster newMonster = (monster) malloc(sizeof(monster));
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

monster (*monsterArrayFirstHalf[3])() = {createJawurm1, createBlouni, createKeliko};
monster (*monsterArraySecondHalf[3])() = {createJawurm2, createRedoni, createMangoustine};
monster (*miniBossArray[2])() = {createEldan, createPyrox};

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