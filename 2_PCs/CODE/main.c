#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include "UDP.h"

int main()
{
    pthread_t t_Servo;
    pthread_t t_Rear;
    pthread_t t_Front;

    UDP u_Servo, u_Rear, u_Front;
    u_Servo = InitUDP(5000);
    u_Rear = InitUDP(5001);
    u_Front = InitUDP(5002);

    ReadUDP(u_Servo);
    // ReadUDP(u_Rear);
    // ReadUDP(u_Front);

    // pthread_create(&t_Servo, NULL, ReadUDP, u_Servo);
    // test = InitUDP(5000);
    /* code */
    return 0;
}
