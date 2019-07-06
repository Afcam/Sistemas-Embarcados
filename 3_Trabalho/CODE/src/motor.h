#ifndef motor
#define motor

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include <wiringPi.h>
#include <softPwm.h>
 #include "UnrealEngine.h"

//Define GPIO Pin

// Orientation Servos
#define YAW 26
#define PITCH 23
//Servos PWM
#define sClock 384
#define sRange 1000

//Rear Motor H-bridge
#define PwmA 25
#define PwmB 27
// #define FBpwm 25
#define minValue 0
#define pwmRange 255
#define dcClock 384

//Front Motor
#define Left 2
#define Right 3

#define Superior 4
#define Meio  5
#define Baixo 6

void SG90Setup(int Pin);
void DCRearSetup();
void DCFrontSetup(); 
void DCFrontSetup();
void DCFront(char *msg);
void DCRear(Rear *Motor);

#endif
