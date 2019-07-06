#ifndef UnrealEngine
#define UnrealEngine

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    float Pich ;
    float Yaw ;
    float Roll;
} Axes;

typedef struct
{
    char Dir;
    int Speed ;

} Rear;

Axes *UEAxes(char *msg);
Rear *UERear(char *msg);

#endif
