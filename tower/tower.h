//
// Created by loicc on 08/06/2022.
//




#ifndef TOWER_TOWER_H
#define TOWER_TOWER_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "../monsters/monsters.h"


struct room_;
typedef struct room_ *room;

room createRoom(float m_floor, monster m_monster, int m_event);

void createTowerBoucle(room previous1, room previous2, room previous3, room previous4);

room createTower();

room goNextFloor(room actualRoom);

room menuChoixNextSalle(room actualRoom);

void onEvent(room actualRoom);
#endif //TOWER_TOWER_H
