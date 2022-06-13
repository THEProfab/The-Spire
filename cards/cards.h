//
// Created by César on 16/05/2022.
//

#ifndef THE_SPIRE_CARDS_H
#define THE_SPIRE_CARDS_H

#include <stdbool.h>
#include "../effects/effects.h"

struct cards_ {

    char* name;
    int rarity; //can be : 1=basique, 2=commune, 3=atypique, 4=rare, 5=special
    int costEnegry;// max = 3
    int costMana;// max = 20
    effects effect[8];// their can have 8 effects max
    char* textTech;
    char* textDescription;
    bool abyssal;// is abyssal or not - 1 or 0
};
typedef struct cards_ * cards;

#endif //THE_SPIRE_CARDS_H

cards newCard(char* name,int rarity,effects effect[8],int costEnergy,int costMana,char* textTech,char* textDescription,bool abyssal);
void cardActivation(cards card,monster monster);