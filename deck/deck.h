//
// Created by César on 30/05/2022.
//

#ifndef THE_SPIRE_DECK_H
#define THE_SPIRE_DECK_H

#include <stdio.h>
#include "cards.c"

struct deck_ ;
typedef struct deck_ * deck;

#endif //THE_SPIRE_DECK_H

deck createDeck(cards card);
void addCard(deck currentDeck, cards card);
void displayDeck(deck deck);
cards * returnDeck(deck deck);
//cards shuffle(cards deck[21]);