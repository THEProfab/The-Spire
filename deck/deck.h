//
// Created by César on 30/05/2022.
//

#ifndef THE_SPIRE_DECK_H
#define THE_SPIRE_DECK_H

#include <stdio.h>
#include "../cards/cards.h"

struct deck_ {
    cards card;
    struct deck_ * next;
};
typedef struct deck_ * deck;

#endif //THE_SPIRE_DECK_H

deck createDeck(cards card);
void addCard(deck currentDeck, cards card);
void displayDeck(deck deck);
cards * returnDeck(deck deck);