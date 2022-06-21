#ifndef THE_SPIRE_MONSTERS_H
#define THE_SPIRE_MONSTERS_H

struct monster_ {
    int id;
    int hp;
    char *name;
    int dodge; //Reduces the next damage received by x, reset to zero at the end of the turn
    int strength; //Inflicts extra damage
    int dexterity; //Gives bonus dodge
    int fire; //Fire value, halves at the end of the turn, inflicts damage to this entity
    int weak; //Attack decreased by 25%, rounded up, for x turns
    int slow; //Escape gained divided by two, decreases by 1 per turn
};

typedef struct monster_ *monster;

#include "../effects/effects.h"

//First half monsters
monster createJawurm1();

void jawurm1Abilities();

void announceAbilityJawurm1();

monster createBlouni();

void blouniAbilities();

void announceAbilityBlouni();

monster createKeliko();

void kelikoAbilities();

void announceAbilityKeliko();

//Second half monsters
monster createJawurm2();

void jawurm2Abilities();

void announceAbilityJawurm2();

monster createRedoni();

void redoniAbilities();

void announceAbilityRedoni();

monster createMangoustine();

void mangoustineAbilities();

void announceAbilityMangoustine();

//Minibosses
monster createEldan();

void eldanAbilities();

void announceAbilityEldan();

monster createPyrox();

void pyroxAbilities();

void announceAbilityPyrox();

//Boss
monster createKeeperOfTheFeather();

void keeperOfTheFeatherAbilities();

void announceAbilityKeeperOfTheFeather();

monster pickAMonster13();

monster pickAMonster59();

monster pickAMiniBoss();

#endif //THE_SPIRE_MONSTERS_H