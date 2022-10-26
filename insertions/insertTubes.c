#include <stdio.h>
#include <string.h>
#include "insertTubes.h"


/**
 * pré: list et tube existent et sont initialisés
 * pos: tube est ajouté à la fin de list
*/
void appendTube(TUBESLIST * list, TUBE * tube){

    if(list->tail == NULL) {
        list->tail = tube;
        list->head = tube;
    } else {
        list->tail->nextTube = tube;
        tube->previousTube = list->tail;
        list->tail = tube;
    }
    list->length++;
}
