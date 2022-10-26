#include <stdio.h>
#include <stdlib.h>
#include "appearance.h"
#define NB_TYPES_BALLS 4 
#define GRID_SIZE 438
#define CHAR_PER_LAYER 72
#define NB_CHARS_IN_BOX 5
#define NB_SPACES_IN_BOX 3
#define NB_LINE_FEED 5
#define NB_LAYERS 6
#define NB_TUBES 9

/**
 * pre: tube existe et est initialisé, index est initialisé
 * pos: tube et index sont inchangés
 * res: renvoi ball si à la position index du tube il y a une ball sinon retourne null  
*/
BALL * getCurrentTubeBall(TUBE * tube, int index){
    BALL * ball = NULL;
    BALL * tmp;
    int length = tube->ballsList->length;
    int iterations = NB_TYPES_BALLS - (index - 1);
    boolean isTimeToPlace = NB_TYPES_BALLS - length + 1 <= index;

    if(tube->ballsList->head != NULL && iterations > 0 && isTimeToPlace){
        tmp = tube->ballsList->tail;
        int cpt = 0;
        while(cpt < iterations){
            ball = tmp;
            tmp = tmp->previousBall;
            cpt++;
        }            
    } 
    return ball;
}

/**
 * pré: list existe et est initialisé
 * pos: list est inchangé
 * rés: un pointeur de caractères qui représente la décoration de la liste des tubes par rapport à son état 'isCompleted'
*/

char * drawTubes(TUBESLIST * list){

    TUBE * tube = list->head;
    BALL * ball = tube->ballsList->head;

    char * grid = malloc(GRID_SIZE);
    char tubeTop[][NB_CHARS_IN_BOX+NB_SPACES_IN_BOX] = { {":   :   "},{"+===+   "} };
    char tubeFloor[][NB_CHARS_IN_BOX+NB_SPACES_IN_BOX]  = {{"-----   "},{"+===+   "}};
    char tubeWall[]   = {"|   |   "};
    char nbTubes[] = {'1','2','3','4','5','6','7','8','9'};
    int cpt = 0;

    for(int i = 0; i < NB_LAYERS; i++){
        for(int k = 0; k < NB_TUBES; k++){
            ball =  i > 0 && i < 5 ? getCurrentTubeBall(tube,i) : NULL; // chars between 1 and 5 layer
            for(int j = 0; j < NB_CHARS_IN_BOX+NB_SPACES_IN_BOX; j++){
                if(cpt < CHAR_PER_LAYER){
                    *(grid+cpt) = tubeTop[ tube->isCompleted ][j];
                } else if(cpt > CHAR_PER_LAYER && cpt < CHAR_PER_LAYER*5+NB_LINE_FEED-1) {
                    if(ball != NULL && 5 / 2 == j) 
                        *(grid+cpt) = ball->type; 
                    else 
                        *(grid+cpt) = tubeWall[j];
                } else {
                    if(5/2 == j) 
                        *(grid+cpt) = nbTubes[k]; 
                    else 
                        *(grid+cpt) = tubeFloor[ tube->isCompleted ][j];
                }                
                cpt++;
            }
            tube = tube->nextTube;
        }
        tube = list->head;
        
        if(i == NB_LINE_FEED)
            *(grid+cpt) = '\0';
        else 
            *(grid+cpt) = '\n';

        cpt++;
    }
    return grid;
}


/**
 * précondition: tubesDrawn existe et est initialisé
 * postcondition: affiche tubesdrawn
*/
void displayTubes(char * tubesDrawn){
    printf("\n\n\t\t");
    for(int i = 0; i < GRID_SIZE; i++){
        printf("%c",*(tubesDrawn+i));
        if(*(tubesDrawn+i) == '\n')
            printf("\t\t");
    }
    printf("\n");
}
