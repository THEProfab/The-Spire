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

//TODO :pour marc standby :

cards * returnDeckTab(deck deck)
{
    static cards *tabDeck;
    int i=0;
    do
    {
        tabDeck[i]=deck->card;
        deck=deck->next;
        i++;
    }while(deck!=NULL);
    return tabDeck;
}

deck returnDeck(cards *tabDeck)
{
    deck decks = createDeck(tabDeck[0]);
    deck debutDeck = decks;
    int i=1;
    do
    {
        addCard(decks,tabDeck[i]);
        i++;
    }while(i<sizeof(tabDeck));
    return debutDeck;
}

// fin.

cards shuffle(cards *tabDeck)
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

//TODO : pour marc

//5 strikes (6 dégâts) et 5 esquives (5 points d’esquive)

deck startingDeck()
{
    deck deck;
    cards cardStrike = createStrike();
    cards cardEsquive = createEsquive();
    cards cardSpectreComplet = createSpectreComplet();
    for (int i=0;i<5;i++)
    {
        addCard(deck,cardStrike);
    }
    for (int i=0;i<5;i++)
    {
        addCard(deck,cardEsquive);
    }
    addCard(deck,cardSpectreComplet);
    return deck;
}

cards createStrike()
{
    effects effect[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    effect[0] = newEffect(1,6);
    cards cardStrike = newCard("Strike",1,effect,1,0,"Inflige 6 dégâts","L’attaque de base",0);
    return cardStrike;
}

cards createEsquive()
{
    effects effect[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    effect[0] = newEffect(2,5);
    cards cardEsquive = newCard("Esquive",1,effect,1,0,"Donne 5 points d’esquive","L’esquive de base",0);
    return cardEsquive;
}

cards createDoubleStrike()
{
    effects effect[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    effect[0] = newEffect(1,4);
    effect[1] = newEffect(1,4);
    cards card = newCard("Double strike",2,effect,1,0,"Attaque deux fois pour 4 dégâts","Démultiplicateur de force",0);
    return card;
}

cards createBouleDeFeu()
{
    effects effect[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    effect[0] = newEffect(2,6);
    cards cardBouleDeFeu = newCard("Boule de feu",2,effect,0,20,"Inflige 6 points de feu","Un classique des mages débutants",0);
    return cardBouleDeFeu;
}

cards createCoupAffaiblissant()
{
    effects effect[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    effect[0] = newEffect(1,3);
    effect[1] = newEffect(4,2);
    cards cardStrike = newCard("Coup affaiblissant",2,effect,2,0,"Inflige 3 dégâts et rends l’ennemi faible pour 2 tours","Permet d’attaquer tout en se défendant",0);
    return cardStrike;
}

cards createAcceleration()
{
    effects effect[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    effect[0] = newEffect(3,4);
    effect[1] = newEffect(5,1);
    cards card = newCard("Acceleration",2,effect,1,10,"Inflige Lent pour un tour et donne 4 points d’esquive","Ne ralenti pas exactement les adversaires; tout est question de perception.",0);
    return card;
}

cards createSurmenage()
{
    effects effect[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    effect[0] = newEffect(6,2);
    effect[1] = newEffect(1,5);
    cards card = newCard("Surménage",3,effect,1,20,"Augmente les dégâts de 2, mais vous inflige 5 dégâts","Permet de frapper plus fort, mais attention aux courbatures!",0);
    return card;
}

cards createPostureDefensive()
{
    effects effect[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    effect[0] = newEffect(7,2);
    effect[0] = newEffect(6,-1);
    cards card = newCard("Strike",3,effect,0,0,"Dextérité +2, mais Force -1","Permet de mieux esquiver, mais faire durer les combats plus longtemps",0);
    return card;
}

cards createConcentration()
{
    effects effect[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    effect[0] = newEffect(8,50); // TODO: creer MANA
    cards card = newCard("Concentration",3,effect,3,0,"Recharge 50 points de mana","Important si les combats durent longtemps",0);
    return card;
}

cards createIncendie()
{
    effects effect[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    effect[0] = newEffect(2,10);
    effect[0] = newEffect(2,5);
    cards card = newCard("Concentration",3,effect,3,0,"Recharge 50 points de mana","Important si les combats durent longtemps",0);
    return card;
}

cards createPulveriser()
{
    effects effect[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    effect[0] = newEffect(1,30);
    cards card = newCard("Pulvériser",4,effect,3,0,"Inflige 30 dégâts, Abyssal","Blam!",1);
    return card;
}

cards createSpectreComplet()
{
    effects effect[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    effect[0] = newEffect(2,3);
    effect[1] = newEffect(1,6);
    effect[2] = newEffect(6,1);
    effect[3] = newEffect(5,1);
    effect[4] = newEffect(4,1);
    effect[5] = newEffect(7,1);
    effect[6] = newEffect(3,5);
    cards card = newCard("Spectre complet",4,effect,2,20,"Donne différents bonus. Abyssal.","Un bonus pour chaque couleur de l’arc-en-ciel.Un bonus pour chaque couleur de l’arc-en-ciel.",1);
    return card;
}
