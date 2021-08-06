#include <stdio.h>
#include <stdlib.h>
#include "elevator.h"






// typedef struct _Building
// {
//     int nbFloor;               // nombre d’étage des l’immeuble
//     Elevator *elevator;        // la cabine d’ascenseur
//     PersonList **waitingLists; // array of waiting list (one per floor)
// } Building;



Elevator * create_elevator(int capacity, int currentFloor, PersonList * persons){
    Elevator * E = malloc(sizeof(Elevator));
    E->capacity = capacity;
    E->currentFloor = currentFloor;
    E->targetFloor = currentFloor;
    E->persons = persons;
    return E;
}



Building * create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists){
    Building * B = malloc( sizeof( Building ) );
    B->nbFloor = nbFloor;
    B->elevator = elevator;
    B->waitingLists = waitingLists;
    return B;
}
PersonList * exitElevator(Elevator *e){
    //pour chaque personne dans l'ascenseur, on prend celles qui veulent descendre
    //(dest == currentFloor) et on les supprime de la PersonList
    //on change ensuite le nombre de personnes dans l'ascenseur
}
PersonList * enterElevator(Elevator *e, PersonList *list);
void stepElevator(Building *b);