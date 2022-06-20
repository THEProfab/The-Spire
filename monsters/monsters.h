#ifndef THE_SPIRE_MONSTERS_H
#define THE_SPIRE_MONSTERS_H

#include "../effects/effects.h"

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
};

typedef struct monster_ *monster;

//First half monsters
monster createJawurm1();

void jawurm1Abilities();

monster createBlouni();

void blouniAbilities();

monster createKeliko();

void kelikoAbilities();

//Second half monsters
monster createJawurm2();

void jawurm2Abilities();

monster createRedoni();

void redoniAbilities();

monster createMangoustine();

void mangoustineAbilities();

//Minibosses
monster createEldan();

void eldanAbilities();

monster createPyrox();

void pyroxAbilities();

//Boss
monster createKeeperOfTheFeather();

void keeperOfTheFeatherAbilities();

monster pickAMonster13();

monster pickAMonster59();

monster pickAMiniBoss();

void monsterMain();

#endif //THE_SPIRE_MONSTERS_H