#include <stdio.h>
#include <stdlib.h>
#include "interactions.h"
#include "../utils/functions.h"
#include "../structures/structures.h"
#define read "r"
#define splashScreen "../data/splashScreen.txt"


/**
 * pré: ../data/splashScreen.txt existe
 * pos: imprime le fichier ../data/splashScreen.txt
 * rés: 
*/
void displaySplashScreen(){
    FILE * screen = getFile(splashScreen,read);
    char charReadCode;
    do{
        charReadCode = fgetc(screen);
        printf("%c", charReadCode);
    }while(charReadCode != EOF);
    fclose(screen);
    flushStdin();    
}


/**
 * pré: forbiddenIndex est initialisé
 * pos: forbiddenIndex est inchangé
 *      imprime à l'écran le texte d'erreur en fonction de forbiddenIndex
 * rés: //
*/
void showProhibitions(int forbiddenIndex){
    switch (forbiddenIndex){
    case 1:
        printf("\t\tThis tube is completed. :D\n");
        break;
    case 2:
        printf("\t\tThis tube is filled. :(\n");
        break;
    case 3:
        printf("\t\tThe departure tube and the destination tube are the same. :(\n");
        break;
    case 4:
        printf("\t\tYou cannot add on a different letter. :(\n");
        break;
    case 5:
        printf("\t\tThe departure tube is empty. :(\n");
        break;
    case 6:
        printf("\t\tThe come back trick was already use. :/\n");
        break;
    
    default:
        break;
    }
}


/**
 * pré: requestIndex est initialisé
 * pos: requestIndex est inchangé
 *      imprime à l'écran le texte qui correspond à requestIndex
 * rés:
*/
void showRequests(int requestIndex){
    switch (requestIndex){
    case 1:
        printf("\t\tPlease enter the number of the current tube [1-9].\n");
        break;
    case 2:
        printf("\t\tPlease enter the number of the destination tube [1-9].\n");
        break;
    default:
        break;
    }
}


/**
 * pré: list existe et est initialisé
 * pos: list est inchangé, demande une saisi au clavier
 * rés: retourne la saisie au clavier ssi 
 *      c'est un chiffre compris entre le nombre de boule ou si
 *      c'est -1 car il permet de quitter la partie ou si 
 *      c'est -2 car il permet de revenir sur un tour 
*/
int getUserRequest(TUBESLIST * list){
    int choice;
    do{
        scanf("%d",&choice);
        if((choice > list->length || choice < 0) && choice != -1 && choice != -2)
            printf("Enter -1 if you want to quit.\n");
        flushStdin();
    }while(choice > list->length || choice < -2 || choice == 0);
    
    return choice;
}


/**
 * pré: //
 * pos: demande au joueur s'il veut rejouer
 *      boucle cette question tant que sa réponde n'est pas 0 ou 1
 * rés: vrai ssi l'utilisateur saisi 1
*/
boolean isEndOfGame(){
    boolean isEnd;
    do{
        printf("Do you want play again ? Enter 1 for yes and 0 for no.\n");
        scanf("%d",&isEnd);
        flushStdin();
    }while(isEnd != 1 && isEnd != 0);
    clrsrc();
    return isEnd;
}


/**
 * pré: //
 * pos: affiche un message de félicitations au joueur
 * rés: //
*/
void showWin(){
    printf("Well done!! You finished the puzzle. :D\n");
}