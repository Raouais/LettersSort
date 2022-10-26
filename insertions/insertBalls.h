#ifndef INSERTBALLS_H
#define INSERTBALLS_H
#include "../structures/structures.h"

extern void appendBall(BALLSLIST*,BALL*);
extern void app(BALLSLIST*,BALL*);
extern void appat(BALLSLIST*,BALL*,int);
extern BALL * getCurrentBallFromBeginning(BALLSLIST*,int);
extern BALL * getCurrentBallFromTheEnd(BALLSLIST*,int);
extern void insertBallBetween(BALL*,BALL*);

#endif