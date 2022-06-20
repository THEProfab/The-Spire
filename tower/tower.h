//
// Created by loicc on 08/06/2022.
//
#include "../monsters/monsters.h"



#ifndef TOWER_TOWER_H
#define TOWER_TOWER_H

#include <stdlib.h>
#include <time.h>
#include <stdio.h>



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
    int floor;
    // Next room
    struct room_ *above;
    struct room_ *straight;
    struct room_ *below;
    struct room_ *entryPlus;
    struct room_ *previousRoom;
    // What's in the room
    monster monster;
    int event;
};
// type def
typedef struct room_ *room;

room createRoom(float m_floor, monster m_monster, int m_event,room previousRoom);

void createTowerBoucle(room previous1, room previous2, room previous3, room previous4);

room createTower();

room goNextFloor(room actualRoom);

room menuChoixNextSalle(room actualRoom,int event);

void onEvent(room actualRoom);
void eventTP(room actualRoom);
#endif //TOWER_TOWER_H
