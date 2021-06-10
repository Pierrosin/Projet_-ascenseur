#ifndef LISTE
#define LISTE
#include "date.h"

typedef struct _Liste {
    date * head;
    struct _Liste * tail;
} Liste;

Liste * create_liste( date * d );
Liste * create_liste_nulle( );
Liste * insert_debut( date * date , Liste * liste );
void insert_fin( date * date , Liste * liste );
void print_liste( Liste * liste );
int est_fin_liste( Liste * liste );

#endif