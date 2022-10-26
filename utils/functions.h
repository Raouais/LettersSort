#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>

extern void flushStdin();
extern int isUnixLike();
extern void clrsrc();
extern int read(char*,int);
extern int getRandomBetween(int min, int max);
extern FILE * getFile(const char * file_path, const char * mode);

#endif
