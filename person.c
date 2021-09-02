#include <stdio.h>
#include <stdlib.h>
#include "person.h"

Person *create_Person(int src, int dest)
{
    Person *p = malloc(sizeof(Person));
    p->src = src;
    p->dest = dest;
    return (p);
}

void print_Person(Person *p)
{
    printf("%d%d", p->src, p->dest);
}

PersonList *create_PersonList(Person *p)
{
    PersonList *l = malloc(sizeof(PersonList));
    l->head = p;
    l->tail = NULL;
    return (l);
}

PersonList *insert(Person *p, PersonList *plist)
{
    PersonList *L = create_PersonList(p);
    L->tail = plist;
    return L;
}

void print_PersonList(PersonList *liste)
{
    PersonList *liste_tmp = liste;
    printf("[ ");
    while (liste_tmp)
    {
        print_Person(liste_tmp->head);
        printf(" ");
        liste_tmp = liste_tmp->tail;
    }
    printf("]\n");
}

PersonList *insert_end(Person *p, PersonList *L)
{
    if (!L)
    {
        return create_PersonList(p);
    }
    else
    {
        PersonList *l = create_PersonList(p);
        PersonList *liste_tmp = L;
        while (liste_tmp->tail)
        {

            liste_tmp = liste_tmp->tail;
        }
        liste_tmp->tail = l;
        return L;
    }
}

int egalPerson(Person *p1, Person *p2)
{
    return (p1->dest == p2->dest && p1->src == p2->src);
}

int len(PersonList *L)
{
    int len = 0;
    PersonList *liste_tmp = L;
    while (liste_tmp)
    {
        len++;
        liste_tmp = liste_tmp->tail;
    }
    return len;
}

PersonList *removePerson(Person *p, PersonList *L)
{
    // on crée une liste dans laquelle on ajoute toutes les personnes dans L qui ne sont pas p
    PersonList *l = NULL;
    PersonList *liste_tmp = L;
    while (liste_tmp)
    {
        Person *Head = liste_tmp->head;
        if (!egalPerson(Head, p))
        {
            insert_end(Head, l);
        }
    }
    return l;
}

// //JEUX DE TEST

// void main()
// {
//     Person *p = create_Person(3, 4);
//     Person *q = create_Person(1, 2);
//     Person *r = create_Person(5, 6);
//     print_Person(p);
//     printf("\n");
//     PersonList *L = create_PersonList(p);
//     print_PersonList(L);
//     L = insert(q, L);
//     print_PersonList(L);
//     insert_end(r, L);
//     print_PersonList(L);
//     L = NULL;
//     L = insert(p, L);
//     print_PersonList(L);
// }