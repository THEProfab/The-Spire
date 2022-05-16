//
// Created by César on 16/05/2022.
//
#include <bool.h>
#include "effects.h"

struct effects_ {
    int type; // 1=damage, 2=fire, 3=dodge, 4=weakness, 5=slowness, 6=strength, 7=dextertie, 8-Abyssal
    int value; // power, turn...
    bool target; // 0=monster - 1=Peter
};

void damage(int value, bool target)
{

}