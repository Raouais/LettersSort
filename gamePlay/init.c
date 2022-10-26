#include <stdio.h>
#include <stdlib.h>
#include "../insertions/insertBalls.h"
#include "../insertions/insertTubes.h"
#include "../removals/removeBall.h"
#include "../design/appearance.h"
#include "../design/gameDesign.h"
#include "../utils/functions.h"
#include "interactions.h" 
#include "menu.h"
#include "gamePlay.h"
#include "init.h"
#define true 1
#define false 0
#define ERROR_COMPLETED_TUBE 1
#define ERROR_FILLED_TUBE 2
#define ERROR_SAME_TUBE 3
#define ERROR_DIFFERENT_LETTER_TUBE_TOP 4
#define ERROR_EMPTY_TUBE 5
#define ERROR_TRICK 6
#define QUIT -1
#define TRICK -2
#define REQUEST_GET_CURRENT_TUBE 1
#define REQUEST_GET_DESTINATION_TUBE 2

void initGame(){

    BALLSLIST * ballsList = NULL;
    TUBESLIST * tubesList = NULL;

    boolean isWin;
    boolean isNotStopGame;
    boolean isNotEndGame = true;

    while(isNotEndGame){
        clrsrc();
        isNotStopGame = true;
        char * tubeDrawn;

        ballsList = getBallListInitialised();
        tubesList = getTubeListInitialised();
        generateTubes(tubesList);
        generateBalls(ballsList);
        shuffleBallsList(ballsList);
        dealtBallsInTubes(tubesList,ballsList);
        free(ballsList);
        
        tubeDrawn = drawTubes(tubesList);
        displayTubes(tubeDrawn);
        free(tubeDrawn);
        
        isWin = false;      
        int comeBack = 1;
        
        TUBE * saveOld = NULL;
        TUBE * saveNew = NULL;  

        while(isNotStopGame && !isWin){
            showRequests(REQUEST_GET_CURRENT_TUBE);
            int oldPlace = getUserRequest(tubesList);
            int newPlace = 0;
            if(oldPlace != QUIT && oldPlace != TRICK){
                showRequests(REQUEST_GET_DESTINATION_TUBE);
                newPlace = getUserRequest(tubesList);
            }
            boolean try = false;

            if(oldPlace > 0 && newPlace > 0){
                TUBE * oldTube = getCurrentTube(tubesList,oldPlace);
                TUBE * newTube = getCurrentTube(tubesList,newPlace);
                
                if(newTube->isCompleted || oldTube->isCompleted){
                    showProhibitions(ERROR_COMPLETED_TUBE);
                } else if(compareTubes(oldTube,newTube)){
                    showProhibitions(ERROR_SAME_TUBE);
                } else if(newTube->isFilled){
                    showProhibitions(ERROR_FILLED_TUBE);
                } else if(oldTube->isEmpty){
                    showProhibitions(ERROR_EMPTY_TUBE);
                } else if(!newTube->isEmpty && !isSameTubeBall(oldTube,newTube)){
                    showProhibitions(ERROR_DIFFERENT_LETTER_TUBE_TOP);
                } else {
                    swapBalls(oldTube,newTube);
                    try = true;
                    if(comeBack > 0){
                        saveOld = oldTube;
                        saveNew = newTube;
                    }
                }
            } else if ((oldPlace == TRICK || newPlace == TRICK) && saveNew != NULL && saveOld != NULL){
                if(comeBack > 0){
                    swapBalls(saveNew,saveOld);
                    comeBack--;
                    try = true;
                } else{ showProhibitions(ERROR_TRICK);}

            } else if(oldPlace == QUIT || newPlace == QUIT) {    
                isNotEndGame = false;
                isNotStopGame = false;
            }

            
            if(isNotStopGame && try){
                clrsrc();
                tubeDrawn = drawTubes(tubesList);     
                displayTubes(tubeDrawn);
                free(tubeDrawn);
                isWin = isWinner(tubesList); 
            }

            if(isWin){
                showWin();
                isNotEndGame = isEndOfGame();
            }
        }
        flushTubes(tubesList);
        free(tubesList);
    }
    menu();
}