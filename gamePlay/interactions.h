#ifndef INTERACTIONS_H
#define INTERACTIONS_H
#include "../structures/structures.h"

void displaySplashScreen();
extern void showRequests(int);
extern void showProhibitions(int);
extern int getUserRequest();
extern boolean isEndOfGame();
extern void showWin();

#endif