#include "UnrealEngine.h"

Axes *UEAxes(char *msg)
{
    Axes *Rot = malloc(sizeof(Axes));
    char *token;
    int i = 0;

    token = strtok(msg, " ");
    for (i = 0; token != NULL; i++)
    {
        switch (i)
        {
        case (0):
            // strcpy(Rot->Pich, token);
            Rot->Pich = atof(token + 2);
            if (Rot->Pich < -30)
                Rot->Pich = -30;
            if (Rot->Pich > 40)
                Rot->Pich = 40;

            break;
        case (1):
            // strcpy(Rot->Yaw, token);
            Rot->Yaw = atof(token + 2);
            if (Rot->Yaw < -120)
                Rot->Yaw = -120;
            if (Rot->Yaw > -35)
                Rot->Yaw = -35;
            break;
        default:
            // strcpy(Rot->Roll, token);
            Rot->Roll = atof(token + 2);
            break;
        }
        token = strtok(NULL, " ");
    }
    return Rot;
}

Rear *UERear(char *msg)
{
    Rear *Control = (Rear *)malloc(sizeof(Rear));
    // int Val = atoi(msg);
    int Val = 220;

    // if (Val <= 0)
    // {
    //     Control->Dir = 'B';
    //     Control->Speed = abs(Val);
    // }
    // else
    // {
    //     Control->Dir = 'F';
    //     Control->Speed = abs(Val);
    // }

    switch (*msg)
    {
    case ('F'):
        Control->Dir = 'F';
        Control->Speed = abs(Val);
        break;
    case ('B'):
        Control->Dir = 'B';
        Control->Speed = abs(Val);
        break;
    default:
        break;
    }

    return Control;
}
