#ifndef THE_SPIRE_MONSTERS_H
#define THE_SPIRE_MONSTERS_H

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

monster (*monsterArrayFirstHalf[3])();
monster (*monsterArraySecondHalf[3])();
monster (*miniBossArray[2])();

#endif //THE_SPIRE_MONSTERS_H
