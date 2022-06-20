//
// Created by loicc on 11/05/2022.
//
#include "tower.h"


int nbEvent = 5;


int nbMonstre = 3;





/**
 *
 * @param m_floor
 * @param m_monster
 * @param m_event
 * @param m_sanctuary
 * @return
 */


room createRoom(float m_floor, monster m_monster, int m_event, room m_previousRoom) {
    room output = (room) malloc(sizeof(struct room_));
    output->floor = m_floor;
    output->above = NULL;
    output->straight = NULL;
    output->below = NULL;
    output->entryPlus = NULL;
    output->monster = m_monster;
    output->event = m_event;
    output->previousRoom = m_previousRoom;
    return output;
}


/**
 *
 * @param previous1
 * @param previous2
 * @param previous3
 * @param previous4
 */





/**
 *
 * @return
 */


room createTower() {

    room entry = createRoom(0, NULL, 0, NULL);
    createTowerBoucle(entry, entry, entry, entry);
    return entry;
}
void createTowerBoucle(room previous1, room previous2, room previous3, room previous4) {
    srand(time(NULL));
    if (previous1->floor != 9) {

        room tab[4];
        int test[4] = {1, 2, 1, 1};
        int randMax = 4;
        int select = 5;
        for (int i = 0; i <= 3; ++i) {
            int condition = 0;
            while (condition != 1) {      // FAIRE ATTENTION A VERIFIER
                int pick = rand() % randMax;
                if (test[pick] != 0) {
                    select = pick;
                    condition = 1;
                }
            }
            if (test[select] == 2) {
                tab[i] = createRoom(previous1->floor + 1, NULL, 1 + rand() % nbEvent, NULL);
                test[select] = 0;
            } else if ((test[select] == 1) && (previous1->floor < 3)) {
                tab[i] = createRoom(previous1->floor + 1, pickAMonster13(), 0, NULL);
                test[select] = 0;
            } else if ((test[select] == 1) && (previous1->floor == 3)) {
                tab[i] = createRoom(previous1->floor + 1, NULL, 1, NULL);
                test[select] = 0;
            } else if ((test[select] == 1) && (previous1->floor > 3)) {
                tab[i] = createRoom(previous1->floor + 1, pickAMonster59(), 0, NULL);
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
    if (previous1->floor == 9) {room boss = createRoom(10, createKeeperOfTheFeather(), 0, NULL);

        previous1->above = boss;
        previous1->straight = boss;
        previous2->above = boss;
        previous2->straight = boss;
        previous2->below = boss;
        previous3->above = boss;
        previous3->straight = boss;
        previous3->below = boss;
        previous4->above = boss;
        previous4->straight = boss;
    }

}
/**
 *
 * @param actualRoom
 * @return
 */
room goNextFloor(room actualRoom) {


    do {
        actualRoom = menuChoixNextSalle(actualRoom, 0);
        if (actualRoom->event !=0) {
            onEvent(actualRoom);
        }

    } while (actualRoom->monster == NULL);


    return actualRoom;
}

/**
 *
 * @param actualRoom
 * @return
 */
room menuChoixNextSalle(room actualRoom, int event) {



    int choice = 0;
    if (actualRoom->below == NULL) {

        if (event == 0) {
            printf("1. above\n");
            printf("2. straight\n");
            printf("Que souhaitez-vous faire ? (entrez 1 ou 2) ");
            scanf("%d", &choice);
        } else if (event == 1) {
            choice = 1 + rand() % 3;
            if (choice == 3)choice++;
        } else if (event == 2) {
            printf("1. above\n");
            printf("2. straight\n");
            printf("3. previous\n");
            printf("Que souhaitez-vous faire ? (entrez 1 ou 2) ");
            scanf("%d", &choice);

            if (choice == 3)choice++;
        }

    } else if(actualRoom!=NULL){
        if (event == 0) {
            printf("1. above\n");
            printf("2. straight\n");
            printf("3. below\n");
            printf("Que souhaitez-vous faire ? (entrez 1,2 ou 3) ");
            scanf("%d", &choice);
        } else if (event == 1) {
            choice = 1 + rand() % 4;
        } else if (event == 2) {
            printf("1. above\n");
            printf("2. straight\n");
            printf("3. below\n");
            printf("4. previous room\n");
            printf("Que souhaitez-vous faire ? (entrez 1 ou 2) ");
            scanf("%d", &choice);

        }

    }

    if (choice == 1) {
        //actualRoom->above->previousRoom = actualRoom;
        actualRoom = actualRoom->above;
    } else if (choice == 2) {
        //actualRoom->straight->previousRoom = actualRoom;
        actualRoom = actualRoom->straight;
    } else if (choice == 3) {
        //actualRoom->below->previousRoom = actualRoom;
        actualRoom = actualRoom->below;
    } else if (choice == 4) {
        actualRoom = actualRoom->previousRoom;
    } else {
        printf("\nVous avez saisi un mauvais chiffre !\n\n");
        menuChoixNextSalle(actualRoom, 0);
    }
    return actualRoom;
}

/**
 *
 * @param actualRoom
 */
void onEvent(room actualRoom) {
    int choice = 0;

    if (actualRoom->event == 1) {
        printf("Vous avez trouvez un sanctuaire !!!\n");
        printf("1. Dormez pour regagner la moitié de vos Hp max\n");
        printf("2. Méditer afin d’avoir la possibilité de retirer définitivement une carte du deck principal\n");
        printf("Que souhaitez-vous faire ? (entrez 1 ou 2) ");
        scanf("%d", &choice);

        if (choice == 1) {
            //demandez une fonction
        } else if (choice == 2) {
            //demandez une fonction
        } else {
            printf("\nVous avez saisi un mauvais chiffre !\n\n");
            onEvent(actualRoom);
        }

    } else if (actualRoom->event == 2) {
        printf("Un téléporteur se présente à Peter, mais impossible de savoir vers où il va!\n");
        eventTP(actualRoom);
    } else if (actualRoom->event == 3) {
        printf("Vous tombez dans un piège magique !!!\n");
        printf("1. Transformer tous les strike en esquive\n");
        printf("2. Transformer toutes les esquives en strikes\n");
        printf("Que souhaitez-vous faire ? (entrez 1 ou 2) ");
        scanf("%d", &choice);

        if (choice == 1) {
            //demandez une fonction
        } else if (choice == 2) {
            //demandez une fonction
        } else {
            printf("\nVous avez saisi un mauvais chiffre !\n\n");
            onEvent(actualRoom);
        }
    } else if (actualRoom->event == 4) {

        printf("La salle est vide, mais dans un chaudron encore allumé, une potion est presqueprête. Comment la terminer?\n");
        printf("1. Faire une potion de santé (hp max +10)\n");
        printf("2. Faire une potion de mana (mana max +20)\n");
        printf("Que souhaitez-vous faire ? (entrez 1 ou 2) ");
        scanf("%d", &choice);


        if (choice == 1) {
            //demandez une fonction
        } else if (choice == 2) {
            //demandez une fonction
        } else {
            printf("\nVous avez saisi un mauvais chiffre !\n\n");
            onEvent(actualRoom);
        }
    } else if (actualRoom->event == 5) {
        printf("Vous avez découvert un miniboss en train de dormir !!!\n");
        printf("1. Lancer un combat contre le miniboss\n");
        printf("2. avancer normalement à la prochaine salle\n");
        printf("Que souhaitez-vous faire ? (entrez 1 ou 2) ");
        scanf("%d", &choice);


        if (choice == 1) {
            actualRoom->monster = pickAMiniBoss();
        } else if (choice == 2) {
            printf("\nVous poursuivez votre chemin\n\n");
        } else {
            printf("\nVous avez saisi un mauvais chiffre !\n\n");
            onEvent(actualRoom);
        }
    }


}

void eventTP(room actualRoom) {
    int choice = 0;
    printf("1. Entrer dans le téléporteur et aller dans une pièce adjacente (possibilitéségales d’avancer, revenir en arrière ou de rester au même niveau) \n");
    printf("2. Dépenser 10 points de vie pour garantir d’aller à un endroit choisi\n");
    printf("Que souhaitez-vous faire ? (entrez 1,2 ou 3) ");
    scanf("%d", &choice);


    if (choice == 1) {
        menuChoixNextSalle(actualRoom, 1);
    }
    if (choice == 2) {
        menuChoixNextSalle(actualRoom, 2);
    } else {
        printf("\nVous avez saisi un mauvais chiffre !\n\n");
        eventTP(actualRoom);
    }

}