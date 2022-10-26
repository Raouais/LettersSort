#ifndef REMOVEBALL_H
#define REMOVEBALL_H
#include "../structures/structures.h"

extern void removeBall(BALLSLIST*,int);
extern void removeLastBall(BALLSLIST*);
extern void removeFirstBall(BALLSLIST*);
extern void flushTubes(TUBESLIST * list);
extern void flushBalls(BALLSLIST * list);

#endif