#ifndef THE_SPIRE_MONSTERS_H
#define THE_SPIRE_MONSTERS_H

struct monster_;

typedef struct monster_ *monster;

//First half monsters
monster createJawurm1();

monster createBlouni();

monster createKeliko();

//Second half monsters
monster createJawurm2();

monster createRedoni();

monster createMangoustine();

//Minibosses
monster createEldan();

monster createPyrox();

//Boss
monster createKeeperOfTheFeather();

void monsterMain();

#endif //THE_SPIRE_MONSTERS_H
