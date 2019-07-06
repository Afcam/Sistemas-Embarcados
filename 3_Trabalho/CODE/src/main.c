#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>

#include <wiringPi.h>
#include <softPwm.h>

#include "UDP.h"
#include "motor.h"
#include "UnrealEngine.h"

void *Orientation();
void *RearMotor();
void *FrontMotor();
void DCHardStop();
void BackToCenter();

void recv2(UDP *udp, int pid);

// ========================================================
// Main
// ========================================================
int main()
{
    pthread_t th_Orientation;
    pthread_t th_Rear;
    pthread_t th_Front;

    // Initializes Wiring Pi
    if (wiringPiSetup() == -1)
    {
        fprintf(stdout, "oops: %s\n", strerror(errno));
        return 1;
    }

    pthread_create(&th_Orientation, NULL, Orientation, NULL);
    pthread_create(&th_Rear, NULL, RearMotor, NULL);
    pthread_create(&th_Front, NULL, FrontMotor, NULL);

    /* wait for thread to finish */
    pthread_join(th_Orientation, NULL);
    pthread_join(th_Rear, NULL);
    pthread_join(th_Front, NULL);

    return (0);
}

// ========================================================
// Orientation
// ========================================================
void *Orientation()
{
    UDP *udp_Orientation;
    Axes *AXIS;
    udp_Orientation = UDPSetup(30000);
    fflush(stdout);

    SG90Setup(YAW);
    SG90Setup(PITCH);

    for (;;)
    {
        AXIS = UEAxes(UDPRead(udp_Orientation));
        printf("++ %f %f \n", AXIS->Pich, AXIS->Yaw);
        pwmWrite(PITCH, -AXIS->Pich + 70.0);
        pwmWrite(YAW, -AXIS->Yaw);
    }
}

// ========================================================
// DC Motors Rear
// ========================================================
void *RearMotor()
{
    pid_t pid;
    UDP *udp_Rear;
    Rear *Motor;
    DCRearSetup();
    udp_Rear = UDPSetup(30001);
    fflush(stdout);

    pid = fork();
    if (pid < 0)
    {
        printf("Erro!!!\n");
        exit(-1);
    }

    for (;;)
    {
        Motor = UERear(UDPRead(udp_Rear));
        printf("\n+Rear: %c %d \n", Motor->Dir, Motor->Speed);
        DCRear(Motor);
        delay(10);
        softPwmWrite(PwmA, 0);
        softPwmWrite(PwmB, 0);
    }
}
// ========================================================
// DC Motors Front
// ========================================================

void *FrontMotor()
{
    UDP *udp_Front;
    DCFrontSetup();
    udp_Front = UDPSetup(30002);
    fflush(stdout);
    char *msg;

    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 200000;
    if (setsockopt(udp_Front->sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0)
       { perror("Error");}

    // for (;;)
    // {
    //     msg = UDPRead(udp_Front);
    //     printf("++ %s\n", msg);
    //     DCFront(msg);
    //     // delay(1);

    // }

    for (;;)
    {
        msg = UDPRead(udp_Front);
        if (udp_Front->bytes_read < 0)
        {
            printf("expirou\n");
            int pid;
            pid = fork();

            // Codigo do filho
            if (pid == 0)
            {
                BackToCenter();
            }

            // Codigo do Pai
            else
            {
                recv2(udp_Front, pid);
            }
        }
        else
        {
            // printf("ta aki");
            DCFront(udp_Front->recv_data);
        }

        printf("++ %s\n", udp_Front->recv_data);
        DCFront(udp_Front->recv_data);
    }
}

void recv2(UDP *udp, int pid)
{
    char *msg;

    msg = UDPRead(udp);
    if (udp->bytes_read > 0)
    { //cliente enviou mensagem
        kill(pid, SIGKILL);
        DCFront(udp->recv_data);
    }
    else
    { //tempo expirou de novo
        recv2(udp, pid);
    }
}

void BackToCenter()
{
    int t1, t2, t3, L, R, C;
    char *Lef = "L";
    char *Rig= "R";
    do
    {
        t1 = digitalRead(Superior);
        t2 = digitalRead(Meio);
        t3 = digitalRead(Baixo);

        if ((L = (!(t1) && !(t2) && !(t3))) > 0) //verificar se está em L
        {
            DCFront(Rig);
        }
        else
        {
            if ((R = (!(t1) && t2 && !(t3))) > 0) //verificar se está em R
               {
                   DCFront(Lef);
               }
               else
               {
                   if ((C = (t1 && !(t2) && t3)) > 0) // verificar se está em C
                   {
                       DCHardStop();
                   }
            }
        }

        // DCFront(buffer);

    } while (C != 1);
}

void DCHardStop()
{
    digitalWrite(Left, HIGH);
    digitalWrite(Right, HIGH);
    usleep(10000);
    digitalWrite(Left, LOW);
    digitalWrite(Right, LOW);
}

// ========================================================
// TRASH
// ========================================================
// pthread_t t_Servo;
// pthread_t t_Rear;
// pthread_t t_Front;
// printf("hello ");
// UDP *u_Servo;
// UDP *u_Rear;
// UDP *u_Front;

// u_Servo = InitUDP(30000);
// u_Rear = InitUDP(5001);
// u_Front = InitUDP(5002);
// fflush(stdout);

// wiringPiSetup();

// Normal(u_Servo);
// pthread_create(&t_Servo, NULL, Bosta, (void*)&u_Servo);
// pthread_join(Normal, NULL);
// pthread_join(Normal, NULL);
// pthread_create(&t_Rear, NULL, Normal, (void *)&u_Rear);
// pthread_create(&t_Front, NULL, Normal, (void *)&u_Front);
// while (1)
// {

// }

// void *conometro(void *var)
// {
//     // int *vari=var;
//     for(;;)
//     {
//     printf("\n==Timer: %d == \n",(int *)var);
//     sleep(3);
//     }
// }

// void *fteste()
// {
//     printf("Estoru na tread");
//     pthread_t teste;

//     int variavel;
//     // pthread_create(&te]ç9ste, NULL, conometro, variavel);

//     for(;;)
//     {
//         printf("\n Esperando... = ");
//         printf("%d",variavel);
//         variavel+=1;
//         sleep(1);
//     }
// }
