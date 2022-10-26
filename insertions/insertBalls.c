#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "insertBalls.h"


/**
 * pré: list et ball existent et sont initialisés
 * pos: ball est ajouté à la fin de list
*/
void appendBall(BALLSLIST * list, BALL * ball){

    if(list->tail == NULL) {
        list->tail = ball;
        list->head = ball;
    } else {
        list->tail->nextBall = ball;
        ball->previousBall = list->tail;
        list->tail = ball;
    }
    list->length++;
}

/**
 * pré: list et ball existent et sont initialisés
 * pos: ball est ajouté au début de list
*/
void app(BALLSLIST * list, BALL * ball){
    
    if(list->head == NULL) {
        list->head = ball;
        list->tail = ball;
    } else {
        ball->nextBall = list->head;
        list->head->previousBall = ball;
        list->head = ball;
    }
    list->length++;
}

/**
 * pré: list existe, list et index sont initialisé
 * pos: list et index sont inchangés
 * rés: renvoie l'adresse d'une boule de la liste à l'indice index
*/
BALL * getCurrentBallFromBeginning(BALLSLIST * list, int index){
    BALL * current = list->head;
    BALL * ballTmp = NULL;
    int cpt = 0;
    while(cpt < index) {
        ballTmp = current;
        current = current->nextBall;
        cpt++;
    }
    return ballTmp;
}

/**
 * pré: list existe, list et index sont initialisé
 * pos: list et index sont inchangés
 * rés: renvoie l'adresse d'une boule de la liste à l'indice index
*/
BALL * getCurrentBallFromTheEnd(BALLSLIST * list, int index){
    BALL * current = list->tail;
    BALL * ballTmp = NULL;
    int cpt = list->length;
    while(cpt >= index) {
        ballTmp = current;
        current = current->previousBall;
        cpt--;
    }
    return ballTmp;
}

/**
 * pré: current et ball existent et initialisés
 * pos: current et ball sont inchagés
 * rés: ball est inséré entre current.previousBall et current
*/
void insertBallBetween(BALL * current, BALL * ball){
    BALL * previous = current->previousBall;

    ball->nextBall = current;
    ball->previousBall = previous;

    previous->nextBall = ball;
    current->previousBall = ball;    
}

/**
 * pré: list, ball existent et list, ball et index sont initialisés
 * pos: list, ball et index sont inchangés
 *      ball est inséré à la place index dans list
*/
void appat(BALLSLIST * list, BALL * ball, int index){
    if(index == 1)
        app(list,ball);
    else if (index >= list->length - 1)
        appendBall(list,ball);
    else {
        BALL * current;
        if(index <= list->length/2)
            current = getCurrentBallFromBeginning(list,index);
        else 
            current = getCurrentBallFromTheEnd(list,index);
        
        insertBallBetween(current,ball);
        list->length++;
    } 
}