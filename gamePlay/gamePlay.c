#include <stdio.h>
#include <stdlib.h>
#include "gamePlay.h"
#include "../insertions/insertBalls.h"
#include "../removals/removeBall.h"
#define true 1
#define false 0
#define MAX_BALL_IN_TUBE 4
#define NB_BALLS_PER_TYPE 7


/**
 * pré: tube existe et est initialisé
 * pos: tube est inchangé
 * rés: vrai ssi tube est rempli
*/
boolean isTubeFilled(TUBE * tube){
    BALL * ball = tube->ballsList->head;
    
    int cpt = 0;

    while(ball!=NULL){
        cpt++;
        ball = ball->nextBall;
    }
    return cpt == MAX_BALL_IN_TUBE;
}

/**
 * pré: tube existe et est initialisé
 * pos: tube est inchangé
 * rés: vrai ssi tube est complété
*/
boolean isTubeCompleted(TUBE * tube){
    BALL * ball = tube->ballsList->head;
    char type = ball != NULL ? ball->type : ' '; 
    boolean isNotSame = true;
    int cpt = 0;
    while(ball!=NULL && isNotSame){
        isNotSame = ball->type == type;
        if(isNotSame)
            cpt++;
        ball = ball->nextBall;
    }
    return cpt == MAX_BALL_IN_TUBE;
}


/**
 * pré: old et new existent et sont initialisés
 * pos: old et new sont inchangés
 * rés: vrai ssi la première la ball dans old et new sont de même type
*/
boolean isSameTubeBall(TUBE * old, TUBE * new){
    return old->ballsList->head->type == new->ballsList->head->type;
}


/**
 * pré: old et new existent et sont initialisés
 * pos: old et new sont inchangés
 * rés: vrai ssi la liste de ball dans old est égale à la liste de ball dans new
*/
boolean compareTubes(TUBE * old, TUBE * new){
    return old->ballsList == new->ballsList;
}


/**
 * pré: tube existe et est initialisé
 * pos: tube est inchangé
*/
void updateTube(TUBE * tube){
    tube->isCompleted = isTubeCompleted(tube);
    tube->isFilled = isTubeFilled(tube);
    tube->isEmpty = tube->ballsList->head == NULL;
}


/**
 * pré: oldTube et newTube existent et sont initialisés
 * pos: la première boule de la liste de boule dans oldTube 
 *      est permuté dans la liste de boule de newTube 
*/
void swapBalls(TUBE * oldTube, TUBE * newTube){
    BALL * newBall = oldTube->ballsList->head;
    removeFirstBall(oldTube->ballsList);

    newBall->nextBall = NULL;
    newBall->previousBall = NULL;
    
    app(newTube->ballsList,newBall);
    updateTube(oldTube);
    updateTube(newTube);    
}


/**
 * pré: list existe, list et place sont intialisés
 * pos: list et place sont inchangés
 * rés: renvoi l'adresse d'un tube de la liste à l'indice place 
*/
TUBE * getCurrentTube(TUBESLIST * list, int place){
    TUBE * tube = list->head;
    TUBE * tubeTmp = NULL;
    int cpt = 0;
    while(tube!=NULL && place > cpt){
        tubeTmp = tube;
        tube = tube->nextTube;
        cpt++;
    }
    return tubeTmp;
}


/**
 * pré: list existe et est initialisé
 * pos: list est inchangé
 * rés: vrai ssi 7 tubes de la list ont l'attribut 'isCompleted' à vrai
*/
boolean isWinner(TUBESLIST * list){
    TUBE * tube = list->head;
    int countNbTubesCompleted = 0;
    while(tube!=NULL){
        if(tube->isCompleted)
            countNbTubesCompleted++;
        tube = tube->nextTube;
    }
    return countNbTubesCompleted == NB_BALLS_PER_TYPE;
}