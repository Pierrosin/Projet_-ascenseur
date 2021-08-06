#include <stdio.h>
#include <stdlib.h>
#include "elevator.h"
#include "person.h"

// typedef struct _Building
// {
//     int nbFloor;               // nombre d’étage des l’immeuble
//     Elevator *elevator;        // la cabine d’ascenseur
//     PersonList **waitingLists; // array of waiting list (one per floor)
// } Building;

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons)
{
    Elevator *E = malloc(sizeof(Elevator));
    E->capacity = capacity;
    E->currentFloor = currentFloor;
    E->targetFloor = currentFloor;
    E->persons = persons;
    return E;
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists)
{
    Building *B = malloc(sizeof(Building));
    B->nbFloor = nbFloor;
    B->elevator = elevator;
    B->waitingLists = waitingLists;
    return B;
}

PersonList *exitElevator(Elevator *e)
{
    PersonList *L = NULL;
    PersonList *person_list = e->persons;
    int floor = e->currentFloor;
    while (person_list)
    {
        if (person_list->head->dest != floor)
        {
            L = insert(person_list->head, L);
        }
        person_list = person_list->tail;
    }
    e->persons = L;
    return L;
}

PersonList *enterElevator(Elevator *e, PersonList *list)
{
    PersonList *person_list = e->persons;
    int capacity = e->capacity;
    int floor = e->currentFloor;
    while (len(e->persons) < capacity && list)
    {
        insert_end(list->head, e->persons);
        list = list->tail;
    }
    return list;
}

void stepElevator(Building *b)
{
    int curFloor = b->elevator->currentFloor;
    int tarFloor = b->elevator->targetFloor;
    if (curFloor == tarFloor)
    {
        exitElevator(b->elevator);
        PersonList *new_waiting_list = enterElevator(b->elevator, b->waitingLists[curFloor]);
        b->waitingLists[curFloor] = new_waiting_list;
    }
    else
    {
        if (curFloor < tarFloor)
        {
            b->elevator->currentFloor++;
        }
        else
        {
            b->elevator->currentFloor--;
        }
    }
}

// void main()
// {
//     Elevator *e = create_elevator(3, 0, create_PersonList(create_Person(0, 0)));
//     Person *p = create_Person(3, 0);
//     Person *q = create_Person(0, 2);
//     PersonList *personlist = create_PersonList(p);
//     insert_end(q, personlist);
//     insert_end(q, personlist);
//     PersonList *L = enterElevator(e, personlist);
//     print_PersonList(L);
//     print_PersonList(e->persons);
//     L = exitElevator(e);
//     print_PersonList(L);
// }