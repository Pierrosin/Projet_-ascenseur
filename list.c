#include <stdio.h>
#include <stdlib.h>
#include "list.h"


Liste * create_liste( date * d ) {
    Liste * liste = malloc( sizeof( Liste ) );
    liste->head = d;
    liste->tail = create_liste_nulle( );
    return liste;
}


Liste * create_liste_nulle( ) {
    return NULL;
}

Liste * insert_debut( date * d , Liste * liste ) {
    Liste * L = create_liste( d );
    L->tail = liste;
    return L;
}

void insert_fin( date * d , Liste * liste ) {
    Liste * L = create_liste( d );
    Liste * liste_tmp = liste;
    while ( est_fin_liste( liste_tmp ) ) {
        liste_tmp = liste_tmp->tail;
    }
    liste_tmp->tail = L;
}

void print_liste( Liste * liste ) {
    Liste * liste_tmp = liste;
    printf( "[ " );
    while ( liste_tmp->tail ) {
        print_date( liste_tmp->head );
        if ( est_fin_liste( liste_tmp->tail ) ) {
            printf( "," );
        }

        liste_tmp = liste_tmp->tail;
    }
    printf( " ]\n" );

}

int est_fin_liste( Liste * liste ) {
    if ( liste->tail ) {
        return 1;
    } else return 0;
}
