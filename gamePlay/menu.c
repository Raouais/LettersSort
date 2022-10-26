#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "../utils/functions.h"
#include "../gamePlay/init.h"
#define path_menu "../data/menu.txt"
#define path_rules "../data/rules.txt"
#define read "r"
#define true 1
#define false 0


/**
 * pré: choice est initialisé
 * pos: choice est inchangé
 * rés: vrai ssi choice est compris entre 1 et 3 inclus 
*/
boolean isNotChoiceCorrect(int choice){
    boolean isCorrect = 1;
    if(choice < 1 || choice > 3){
        printf("Please re-enter your choice [1-3]");
        isCorrect = 0;
    }
    return isCorrect;
}


/**
 * pré: "../data/rules.txt" existe
 * pos: affiche le ficheir "../data/rules.txt" à l'écran
 * rés://
*/
void showRules(){
    clrsrc();
    FILE * menu = getFile(path_rules,read);
    char readChar;
    do{
        readChar = fgetc(menu);
        printf("%c",readChar);
    }while(readChar != EOF);
    fclose(menu);
    printf("\n\n\tType enter to return to menu");
    flushStdin();
}


/**
 * pré: choice est initialisé
 * pos: si choice = 1 initialise le jeu
 *      si choice = 2 montre les règles
 *      si choice = 3 arrête le jeu
 * rés: //
*/
void redirect(int choice){
    switch (choice){
    case 1:
        initGame();
        break;
    case 2: 
        showRules();
        menu();
    case 3:
        clrsrc();
        printf("See you soon! :D");
        break;
    }
}


/**
 * pré: "../data/menu.txt" existe
 * pos: imprime le fichier "../data/menu.txt" à l'écran
 *      demande une saisie au jouer et boucle la demande
 *      tant que le joueur n'a pas entré une saisie valide
 * rés: //
*/
void menu(){

    clrsrc();
    FILE * menu = getFile(path_menu,read);
    char readChar;
    do{
        readChar = fgetc(menu);
        printf("%c",readChar);
    }while(readChar != EOF);
    fclose(menu);
    int choice;
    do{
        scanf("%d",&choice);
        flushStdin();
    }while(!isNotChoiceCorrect(choice));

    redirect(choice);
}