#include "fight.h"

// void canPlay(cards card){

// }

// void draw(){

// }

void turn(int turn, monster monster){
    printf("Tour %d", turn);
    printf("hp : Peter %d %s %d\n", currentPlayerHP, monster->name, monster->hp);

    // choix de l'action du monstre, en attente du codage des attaques des monstres
    //printf("") annonce du choix de l'action du monstre

    // piocher 5 cartes
    // deck hand -> création de la main avec la structure de deck puis assage du pointeur à la fonction de pioche ?

    // jouer cartes
    // demander au joueur la carte qu'il souhaite jouer ou s'il souhaite finir son tour
    // vérifier s'il peut jouer une carte

    // prendre en compte les effets / réduire si nécessaire

    // mettre les cartes non jouées dans la défausse

}

void fight(monster monster){
    //displayDeck();
    printf("Peter affronte : %s\n", monster->name);
    printf("hp : Peter %d %s %d\n", currentPlayerHP, monster->name, monster->hp);

    if (currentPlayerHP < maxPlayerHP){
        printf("Peter récupère 6 hp grâce au casse-croûte !\n");
        int testSustain = (currentPlayerHP + 6)%maxPlayerHP; // test pour voir si on dépasse le max d'hp
        if (testSustain>=1 && testSustain<=5){
            currentPlayerHP += 6-testSustain;
        } else {
            currentPlayerHP += 6;
        }
    }

    int turnNb = 1;
    while (monster->hp>0 && currentPlayerHP>0)
    {
        turn(turnNb, monster);
        turnNb++;
    }
    
    // appliquer effets objets
    // vérification présence casse croûte ?


    // pioche = deck actuel
}