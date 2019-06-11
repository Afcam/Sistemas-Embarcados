/**
 * @file UDP.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "UDP.h"

/**
 * @brief 
 * 
 */
UDP InitUDP(int Port)
{
    UDP udp;

    if ((udp.sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("Socket");
        exit(1);
    }

    udp.server_addr.sin_family = AF_INET;
    udp.server_addr.sin_port = htons(Port);
    udp.server_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(udp.server_addr.sin_zero), 8);

    if (bind(udp.sock, (struct sockaddr *)&udp.server_addr,
             sizeof(struct sockaddr)) == -1)
    {
        perror("Bind");
        exit(1);
    }

    udp.addr_len = sizeof(struct sockaddr);

    printf("\nUDPServer Waiting for client on port 5000");
    fflush(stdout);
    return udp;
}

/**
 * @brief 
 * 
 */
void ReadUDP(UDP udp)
{
    while (1)
    {
        udp.bytes_read = recvfrom(udp.sock, udp.recv_data, 1024, 0,
                                   (struct sockaddr *)&udp.client_addr, &udp.addr_len);

        udp.recv_data[udp.bytes_read] = '\0';

        printf("\n(%s , %d) said : ", inet_ntoa(udp.client_addr.sin_addr),
               ntohs(udp.client_addr.sin_port));
        printf("%s", udp.recv_data);
        // return udp.recv_data;
        fflush(stdout);
    }
}
