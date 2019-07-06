#include "motor.h"

void SG90Setup(int Pin)
{
    pinMode(Pin, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(384);  //clock at 50kHz (20us tick)
    pwmSetRange(1000); //range at 1000 ticks (20ms)
    pwmWrite(Pin, 75); // centerss
}

void DCFrontSetup()
{
    pinMode(Left, OUTPUT);
    pinMode(Right, OUTPUT);



    pinMode(Superior, INPUT);
    pinMode(Meio, INPUT);
    pinMode(Baixo, INPUT);
    pullUpDnControl(Superior, PUD_UP);
    pullUpDnControl(Meio, PUD_UP);
    pullUpDnControl(Baixo, PUD_UP);
}

void DCRearSetup()
{
    //PWM
    softPwmCreate(PwmA, minValue, pwmRange);
    softPwmCreate(PwmB, minValue, pwmRange);

    softPwmWrite(PwmA, 0);
    softPwmWrite(PwmB, 0);
}

void DCRear(Rear *Motor)
{

    switch (Motor->Dir)
    {
    case ('F'):
        softPwmWrite(PwmA, Motor->Speed);
        softPwmWrite(PwmB, 0);
        break;
    case ('B'):
        softPwmWrite(PwmA, 0);
        softPwmWrite(PwmB, Motor->Speed);
        // if (Motor->Speed == 0)
        //     softPwmWrite(PwmB, 0);
        // else
        //     softPwmWrite(PwmB, Motor->Speed);
        break;
    default:
        break;
    }
}

void DCFront (char *msg)
{
    
    switch (*msg)
    {
    case ('L'):
        digitalWrite(Left, HIGH);
        digitalWrite(Right, LOW);

        delay(5);
        digitalWrite(Left, LOW);
        break;
    case ('R'):
        digitalWrite(Left, LOW);
        digitalWrite(Right, HIGH);

        delay(5);
        digitalWrite(Right, LOW);
        break;
    default:
        break;
    }
}

// ========================================================
// TRASH
// ========================================================

//H-bridge gpios
//Enables
// pinMode(PwmA, OUTPUT);
// pinMode(PwmB, OUTPUT);

// pinMode(PwmA, PWM_OUTPUT);
// pinMode(PwmB, PWM_OUTPUT);

// pwmSetMode(PWM_MODE_MS);
// pwmSetClock(dcClock);

// pwmWrite(PwmA, 0);
// pwmWrite(PwmB, 0);
// delay(10);