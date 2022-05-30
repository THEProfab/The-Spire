//
// Created by César on 30/05/2022.
//

#include "deck.h"

struct deck_ {
    cards card;
    struct deck_ * next;
};

deck createDeck(cards card){
    deck new = (deck) malloc(sizeof(struct deck_));

    new->card = card;
    new->next = NULL;

    return new;
}

deck addCard(deck currentDeck, cards card)
{
        if (currentDeck == NULL) {
            printf("aïe cassé");
        }

        while (currentDeck->next != NULL) {
            currentDeck = currentDeck->next;
        }
        currentDeck->next = createDeck(card);
}

void displayDeck(deck deck)
{
    int i=0;
    while(deck != NULL)
    {
        i++;
        printf(" carte  : \n");
        printf("%s\n" ,deck->card->name);
        deck = deck->next;
    }
}

card returnDeck(deck deck)
{
    card tabDeck[21];
    for (int i=0;i>20;i++)
    {
        tabDeck[i]=deck->card;
        deck=deck->next;
    }
    return tabDeck;
}

