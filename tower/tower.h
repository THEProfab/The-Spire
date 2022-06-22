#ifndef TOWER_TOWER_H
#define TOWER_TOWER_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "../monsters/monsters.h"
#include "../deck/deck.h"
#include "../effects/effects.h"
#include <stdbool.h>

struct room_ {
    // Room parameters
    int floor;
    // Next room
    struct room_ *above;
    struct room_ *straight;
    struct room_ *below;
    struct room_ *entryPlus;
    struct room_ *previousRoom;
    // Room content
    monster monster;
    int event;
};

typedef struct room_ *room;

room createRoom(float m_floor, monster m_monster, int m_event, room previousRoom);

void createTowerBoucle(room previous1, room previous2, room previous3, room previous4);

room createTower();

room goNextFloor(room actualRoom,deck deck);

room menuChoixNextSalle(room actualRoom, int event);

void onEvent(room actualRoom,deck deck);

void eventTP(room actualRoom);

#endif //TOWER_TOWER_H
