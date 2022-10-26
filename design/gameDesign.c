#include <stdio.h>
#include <stdlib.h>
#include "gameDesign.h"
#include "../insertions/insertTubes.h"
#include "../insertions/insertBalls.h"
#include "../removals/removeBall.h"
#include "../utils/functions.h"
#include "../gamePlay/gamePlay.h"
#define NB_TUBES 9
#define NB_BALLS_PER_TYPE 7
#define NB_TYPES_BALLS 4 
#define MAX_BALL_IN_TUBE 4
#define true 1
#define false 0
//les lettres qu'apparaitront les tubes
const char TYPES_BALL[NB_BALLS_PER_TYPE] = {'A','B','T','S','W','P','G'};

/**
 * pré: //
 * pos: une instance de tube est créé et ses attributs sont 
 *      initialisés à par le pointeur de liste qu'il contient
 * rés: retourne un tube
*/
TUBE * getTubeInitialised(){
    TUBE * tube = malloc(sizeof(TUBE));
    tube->isCompleted = false;
    tube->isFilled = false;
    tube->nextTube = NULL;
    tube->isEmpty = true;
    tube->previousTube = NULL;
    tube->ballsList = NULL;
    return tube;
}


/**
 * pré: type est initialisé
 * pos: une instance de ball est créé et initialisé,
 *      type est inchangé
 * rés: retourne une ball
*/
BALL * getBallInitialised(int type){
    BALL * ball = malloc(sizeof(BALL));
    ball->type = TYPES_BALL[type];
    ball->nextBall = NULL;
    ball->previousBall = NULL;
    return ball;
}


/**
 * pré: tubeslist existe 
 * pos: NB_TUBES sont ajoutés à tubesList
*/
void generateTubes(TUBESLIST * tubesList){
    for(int i = 0; i < NB_TUBES; i++){
        appendTube(tubesList,getTubeInitialised());
    }
}

/**
 * pré: ballsList existe 
 * pos: 28 ball sont ajoutés à ballsList
*/
void generateBalls(BALLSLIST * ballsList){
    for(int i = 0; i < NB_TYPES_BALLS; i++){
        for(int j = 0; j < NB_BALLS_PER_TYPE; j++){
            appendBall(ballsList,getBallInitialised(j));
        }
    }
}


/**
 * pré: list existe et est initialisé 
 * pos: les éléments de la list sont mélangés
*/
void shuffleBallsList(BALLSLIST * list){
    int getRandomBall;
    int getNewPlaceBall;
    for(int i = 0; i < list->length; i++){
        getRandomBall = getRandomBetween(1,list->length);
        getNewPlaceBall = getRandomBetween(1,list->length);
        BALL * current;
        if(getRandomBall <= list->length/2)
            current = getCurrentBallFromBeginning(list,getRandomBall);
        else 
            current = getCurrentBallFromTheEnd(list,getRandomBall);
        
        removeBall(list,getRandomBall);
        appat(list,current,getNewPlaceBall);
    }
}


/**
 * pré: //
 * pos: une liste de boules est créé et initialisé mais ne contient pas de boule
 * rés: retourne une liste de boules
*/
BALLSLIST * getBallListInitialised(){
    BALLSLIST * newBallsList = malloc(sizeof(BALLSLIST));
    newBallsList->head = NULL;
    newBallsList->tail = NULL;
    newBallsList->length = 0;
    return newBallsList;
}


/**
 * pré: //
 * pos: une liste de tube est créé et initialisé mais ne contient pas de tube
 * rés: retourne une liste de tubes
*/
TUBESLIST * getTubeListInitialised(){
    TUBESLIST * tubesList = malloc(sizeof(TUBESLIST));
    tubesList->head = NULL;
    tubesList->tail = NULL;
    tubesList->length = 0;
    return tubesList;
}


/**
 * pré: tubesList et ballsList existent et sont initialisés
 * pos: les ball de ballsList sont ajoutés 4 par 4 dans
 *      le pointeur de liste que contient les tubes dans tubesList 
*/
void dealtBallsInTubes(TUBESLIST * tubesList, BALLSLIST * ballsList){
   BALL * currentBall = ballsList->head;
   BALL * ballTpm;
   TUBE * currentTube = tubesList->head;
   TUBE * tubeTpm = NULL;
   int ctpBallsInTube;
   while(currentTube != NULL){
        BALLSLIST * newBallsList = getBallListInitialised();
        ctpBallsInTube = 0;
        while (ctpBallsInTube < MAX_BALL_IN_TUBE && currentBall != NULL){
            ballTpm = currentBall->nextBall;
            currentBall->nextBall = NULL;
            currentBall->previousBall = NULL;
            appendBall(newBallsList,currentBall);
            currentBall = ballTpm;
            ctpBallsInTube++;
        }
        tubeTpm = currentTube;
        tubeTpm->ballsList = newBallsList;
        updateTube(tubeTpm);
        currentTube = currentTube->nextTube;
   }
}