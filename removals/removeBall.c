#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "removeBall.h"
#define true 1
#define false 0

/**
 * pré: list et ball existent et sont initialisés
 * pos: la première boule de list est retirée
*/
void removeLastBall(BALLSLIST * list){
    if(list->tail->previousBall != NULL){
        list->tail = list->tail->previousBall; 
        list->tail->nextBall = NULL;
    } else {
        list->tail = NULL;
    }
    list->length--;
}


/**
 * pré: list existe et est initialisé
 * pos: la dernière boule de list est retirée
*/
void removeFirstBall(BALLSLIST * list){
    if(list->head->nextBall != NULL){
        list->head = list->head->nextBall;
        list->head->previousBall = NULL;
    } else {
        list->head = NULL;
    }
    list->length--;
}


/**
 * pré: list existe, list et index sont initialisé
 * pos: la boule à l'indice index est retirée de list
*/
void removeBall(BALLSLIST * list, int index){
    
    if(index == 1)
        removeFirstBall(list);
    else if (index == list->length)
        removeLastBall(list);
    else {
        BALL * current = list->head;
        BALL * ballTmp = NULL;
        int cpt = 0;
        while(cpt < index){
            ballTmp = current;
            current = current->nextBall;
            cpt++;
        }
        BALL * next = ballTmp->nextBall;
        BALL * previous = ballTmp->previousBall;
        next->previousBall = previous;
        previous->nextBall = next;
        ballTmp->nextBall = NULL;
        ballTmp->previousBall = NULL;
        list->length--;
    }
}


/**
 * pré: list existe et est initialisé
 * pos: les instance de boules dans list sont supprimés de la mémoire
*/
void flushBalls(BALLSLIST * list){
    BALL * ball = list->head;
    BALL * ballTmp = NULL;//parcours de toute la chaine
    while(ball != NULL){
        ballTmp = ball->nextBall;
        free(ball);//libère la mémoire
        ball= ballTmp;
    }
}


/**
 * pré: list existe et est initialisé 
 * pos: les instance de tube dans list sont supprimés de la mémoire
*/
void flushTubes(TUBESLIST * list){
    TUBE * tube = list->head;
    TUBE * tubeTmp = NULL;//parcours de toute la chaine
    while(tube != NULL){
        tubeTmp = tube->nextTube;
        flushBalls(tube->ballsList);
        free(tube->ballsList);
        free(tube);//libère la mémoire
        tube = tubeTmp;
    }
}

