//
// Created by loicc on 11/05/2022.
//
#include "tower.h"
#include "../monsters/monsters.h"

int nbEvent = 5;

int nbMonstre = 3;


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
    struct room_ *above;
    struct room_ *straight;
    struct room_ *below;
    struct room_ *entryPlus;

    // What's in the room
    monster monster;
    int event;
};

// type def

typedef struct room_ *room;


/**
 *
 * @param m_floor
 * @param m_monster
 * @param m_event
 * @param m_sanctuary
 * @return
 */


room createRoom(float m_floor, monster m_monster, int m_event) {
    room output = (room) malloc(sizeof(struct room_));
    output->floor = m_floor;
    output->above = NULL;
    output->straight = NULL;
    output->below = NULL;
    output->entryPlus = NULL;
    output->monster = m_monster;
    output->event = m_event;
    return output;
}


/**
 *
 * @param previous1
 * @param previous2
 * @param previous3
 * @param previous4
 */


void createTowerBoucle(room previous1, room previous2, room previous3, room previous4) {
    srand(time(NULL));

    if (previous1->floor != 9) {
        room tab[4];
        int test[4] = {1, 2, 1, 1};
        int randMax = 4;
        int select = 5;
        for (int i = 0; i < 3; ++i) {
            int condition = 0;
            while (condition != 1) {      // FAIRE ATTENTION A VERIFIER
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


room createTower() {

    room entry = createRoom(0, NULL, 0);
    createTowerBoucle(entry, entry, entry, entry);
    room actual = entry;

    room boss = createRoom(10, createKeeperOfTheFeather(), 0);

    return entry;
}
