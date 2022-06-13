//
// Created by loicc on 11/05/2022.
//

#include "tower.h"
#include <stdlib.h>
#include <time.h>
/*
//temporary
struct monster_ {
    int id;
    int hp;
    char *name;

    int dodge; //Réduit de x les prochains dégâts reçus, remis à zéro à la fin du tour
    int strength; //Inflige des dégâts supplémentaires
    int dexterity; //Donne de l'esquive bonus
    int fire; //Valeur du feu, diminue de moitié à la fin du tour, inflige des dégâts à cette entité
    int weak; //Attaque diminuée de 25%, arrondi au supérieur, pour x tours
    int slow; //Esquive gagnée divisée par deux, diminue de 1 par tour

    //attack* attacks; //Le tableau d'attaques
};

typedef struct monster_ * monster;

 monster createJawurm1() {
     monster newMonster = (monster) malloc(sizeof(struct monster_));
    int lowerHp = 40;
    int upperHp = 44;
    newMonster->id = 0;
    newMonster->hp = (rand() % (upperHp - lowerHp + 1)) + lowerHp;
    newMonster->name = "Jawurm";
    newMonster->dodge = 0;
    newMonster->strength = 0;
    newMonster->dexterity = 0;
    newMonster->fire = 0;
    newMonster->weak = 0;
    newMonster->slow = 0;
    return newMonster;
}

//Temporary

monster pickAMonster13(){return createJawurm1();}
monster pickAMonster59(){return createJawurm1();}
monster pickABoss(){return createJawurm1();}
int nbMonstre=3;


///Struct of one room
///  Room's parameters
///    @fLoor float
///    @above room*
///    @straight room*
///    @below room*
///    @entryPlus room*
///    @monster monster*
///    @event int
///    @sanctuaty int
struct room_ {

    // Room's parameters
    float floor;

    // Next room
    struct room_* above;
    struct room_* straight;
    struct room_* below;
    struct room_* entryPlus;

    // What's in the room
    monster monster;
    int event;
};

// type def

typedef struct room_* room;


/**
 *
 * @param m_floor
 * @param m_monster
 * @param m_event
 * @param m_sanctuary
 * @return
 */

/*
room createRoom(float m_floor,monster m_monster,int m_event)
{
    room output = (room)malloc(sizeof(struct room_));
    output->floor = m_floor;
    output->above = NULL;
    output->straight = NULL;
    output->below = NULL;
    output->entryPlus = NULL;
    output->monster = m_monster;
    output->event=m_event;
    return output;
}



/**
 *
 * @param previous1
 * @param previous2
 * @param previous3
 * @param previous4
 */

/*
void createTowerBoucle(room previous1,room previous2,room previous3,room previous4) {
    srand(time(NULL));

    if (previous1->floor != 9) {
        room tab[4];
        int test[4] = {1, 2, 1, 1};
        int randMax = 4;
        int select = 5;
        for (int i = 0; i < 3; ++i) {
            int condition=0;
            while (condition!= 1) {      // FAIRE ATTENTION A VERIFIER
                int pick = rand() % randMax;
                if (test[pick] != 0) {
                    select = pick;
                    condition = 1;
                }
            }
            if (test[select] == 2) {
                tab[i] = createRoom(previous1->floor + 1, NULL, 1 + rand() % nbEvent);
                test[select] = 0;
            } else if ((test[select] == 1) && (previous1->floor <= 4)) {
                tab[i] = createRoom(previous1->floor + 1, pickAMonster13(), 0);
                test[select] = 0;
            } else if ((test[select] == 1) && (previous1->floor == 4)) {
                tab[i] = createRoom(previous1->floor + 1, NULL, 1);
                test[select] = 0;
            } else if ((test[select] == 1) && (previous1->floor <= 4)) {
                tab[i] = createRoom(previous1->floor + 1, pickAMonster59(), 0);
                test[select] = 0;
            }
            select = 5;
        }

            if (previous1->floor == 0) {
                previous1->above = tab[0];
                previous1->straight = tab[1];
                previous1->below = tab[2];
                previous1->entryPlus = tab[3];
            } else {
                previous1->above = tab[0];
                previous1->straight = tab[1];
                previous2->above = tab[0];
                previous2->straight = tab[1];
                previous2->below = tab[2];
                previous3->above = tab[1];
                previous3->straight = tab[2];
                previous3->below = tab[3];
                previous4->above = tab[2];
                previous4->straight = tab[3];
            }
            createTowerBoucle(tab[0], tab[1], tab[2], tab[3]);
        }

    }


    /**
     *
     * @return
     */

/*
    room createTower() {

        room entry = createRoom(0, NULL, 0);
        createTowerBoucle(entry, entry, entry, entry);
        room actual = entry;

        room boss = createRoom(10,pickABoss(), 0);

        return entry;
    }
*/