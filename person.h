#ifndef PERSON_H
#define PERSON_H

typedef struct _Person
{
    int src;
    int dest;
} Person;

typedef struct _PersonList
{
    Person *head;
    struct _PersonList *tail;
} PersonList;

Person *create_Person(int src, int dest);

void print_Person(Person *p);

PersonList *create_PersonList(Person *p);

PersonList *insert(Person *p, PersonList *plist);

void print_PersonList(PersonList *liste);

void insert_end(Person *p, PersonList *L);

PersonList *removePerson(Person *p, PersonList *L);

int len(PersonList *L);

#endif