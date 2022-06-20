//
// Created by César on 30/05/2022.
//

#ifndef THE_SPIRE_DECK_H
#define THE_SPIRE_DECK_H

#include <stdio.h>
#include <stdlib.h>
#include "../cards/cards.h"

struct deck_ {
    cards card;
    struct deck_ * next;
};
typedef struct deck_ * deck;

deck createDeck(cards card);
void addCard(deck currentDeck, cards card);
void displayDeck(deck deck);
cards * returnDeck(deck deck);
cards shuffle(cards tabDeck[21]);

#endif //THE_SPIRE_DECK_H