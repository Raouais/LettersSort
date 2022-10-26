#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define true 1
#define false 0

/**
 * précondition: il y a un \n dans le tampom
 * postcondition: vide le tampon s'il nest pas vide 
*/
void flushStdin(){
    int c = 0;
    do{
        c = getchar(); // getchar() récupère un caractère depuis stdin
    }while(c != '\n' && c != EOF);
}

/**
 * précondition: La variable d'environnement PATH est présente sur tout les OS.
 * Tout les systèmes Unix ont comme début un slash ("/") dans le PATH.
 * postcondition: variable PATH inchangé
 * résultat: Si à la position 1 du PATH il y a un slash, alors retourne 1 sinon retourne 0.
*/
int isUnixLike(){
    char * path = getenv("PATH"); //getenv() récupère une variable d'environnement
    return (*path == '/' ? true : false);    
}

/**
 * précondition: La fonction isUnixLike() existe et renvoi soit 1 soit 0.
 * postcondition: Si isUnixLike() renvoi 1 alors efface l'écran avec la
 * commande clear sinon efface l'écran avec la command cls. 
*/
void clrsrc(){
    isUnixLike() == true ? system("clear") : system("@cls");
}

/**
 * précondition: min et max sont initialisés, min < max
 * postcondition: min et max sont inchangées
 * résultat: un nombre entier aléatoire compris entre min et max
*/
int getRandomBetween(int min, int max){
    static int seed = 0;
    if(!seed){
        srand(time(NULL)); 
        seed = 1;
    }
    return rand()%(max-min+1) + min;
}

/**
 * précondition: file_path et mode sont initialisés
 * postcondtion: file_path et mode sont inchangés
 * résultat: si file_path existe retourne un pointeur qui contient l'adresse de file_path sinon retourne null
*/
FILE * getFile(const char * file_path,const char * mode){
    FILE * file = NULL;
    file = fopen(file_path,mode);
    if(file == NULL)
        printf("Le fichier n'a pu etre ouvert.");
        
    return file;
}
