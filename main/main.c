#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../monsters/monsters.h"

int main(){
    srand(time(NULL));
    monsterMain();
    return 0;
}