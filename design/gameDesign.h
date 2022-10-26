#ifndef GAMEDESIGN_H
#define GAMEDESIGN_H
#include "../structures/structures.h"

extern TUBE * getTubeInitialised();
extern BALL * getBallInitialised(int);
extern TUBESLIST * getTubeListInitialised();
extern BALLSLIST * getBallListInitialised();
extern void generateTubes(TUBESLIST*);
extern void generateBalls(BALLSLIST*);
extern void shuffleBallsList(BALLSLIST*);
extern void dealtBallsInTubes(TUBESLIST*,BALLSLIST*);

#endif