#include <stdio.h>
#include <stdlib.h>
#include "utils/functions.h"
#include "gamePlay/interactions.h"
#include "gamePlay/menu.h"

int main(void){
    clrsrc();
    displaySplashScreen();
    menu();
    return EXIT_SUCCESS;
}


