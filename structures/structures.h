#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef int boolean;

typedef struct ball{
    char type; //color
    struct ball * nextBall;
    struct ball * previousBall;
}BALL;

typedef struct ballsList{
    BALL * head;
    BALL * tail;
    int length;
}BALLSLIST;

typedef struct tube{
    boolean isFilled; // est rempli de boules
    boolean isCompleted; // est rempli de boules identiques
    boolean isEmpty; // est vide
    BALLSLIST * ballsList;
    struct tube * nextTube;
    struct tube * previousTube;
}TUBE;

typedef struct tubesList{
    TUBE * head;
    TUBE * tail;
    int length;
}TUBESLIST;


#endif