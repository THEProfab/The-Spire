//
// Created by César on 30/05/2022.
//

#include "deck.h"

deck createDeck(cards card){
    deck new = (deck) malloc(sizeof(struct deck_));

    new->card = card;
    new->next = NULL;

    return new;
}

void addCard(deck currentDeck, cards card)
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

cards * returnDeck(deck deck)
{
    static cards tabDeck[21];
    for (int i=0;i>20;i++)
    {
        tabDeck[i]=deck->card;
        deck=deck->next;
    }
    return tabDeck;
}

cards shuffle(cards tabDeck[21])
{
    srand(time(NULL));
    int seed[21];
    for (int i=0;i<21;i++)
    {
        seed[i]=rand()%22;  //seed initialising
    }
    for (int i=0;i<21;i++)   //exchange the the first card with the number in the seed card
    {
        cards cardChange=tabDeck[i];
        tabDeck[i]=tabDeck[seed[i]];
        tabDeck[seed[i]]=cardChange;
    }
    return tabDeck;
}