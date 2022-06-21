//
// Created by César on 30/05/2022.
//

#ifndef THE_SPIRE_DECK_H
#define THE_SPIRE_DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../cards/cards.h"

struct deck_ {
    cards card;
    struct deck_ * next;
};
typedef struct deck_ * deck;

deck createDeck(cards card);
void addCard(deck currentDeck, cards card);
void displayDeck(deck deck);
cards * returnDeckTab(deck deck);
deck returnDeck(cards *tabDeck);
cards * shuffle(cards deck[21]);

//TODO : pour marc
deck startingDeck();
cards createStrike();
cards createEsquive();
cards createDoubleStrike();
cards createBouleDeFeu();
cards createCoupAffaiblissant();
cards createAcceleration();
cards createSurmenage();
cards createPostureDefensive();
cards createConcentration();
cards createIncendie();
cards createPulveriser();
cards createSpectreComplet();
cards createMartinsFury();

#endif //THE_SPIRE_DECK_H