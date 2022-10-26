#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "../structures/structures.h"

extern boolean isTubeFilled(TUBE*);
extern boolean isTubeCompleted(TUBE*);
extern boolean isSameTubeBall(TUBE*,TUBE*);
extern void updateTube(TUBE*);
extern void swapBalls(TUBE*,TUBE*);
extern TUBE * getCurrentTube(TUBESLIST*,int);
extern boolean compareTubes(TUBE*,TUBE*);
extern boolean isWinner(TUBESLIST*);

#endif