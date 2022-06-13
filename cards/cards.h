//
// Created by César on 16/05/2022.
//

#ifndef THE_SPIRE_CARDS_H
#define THE_SPIRE_CARDS_H

#include <stdbool.h>
#include "effects.c"

struct cards_ ;
typedef struct cards_ * cards;

#endif //THE_SPIRE_CARDS_H

cards newCard(char* name,int rarity,effects effect[8],int costEnergy,int costMana,char* textTech,char* textDescription,bool abyssal);
void cardActivation(cards card,monster monster);