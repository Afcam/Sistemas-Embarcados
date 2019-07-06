#ifndef _UDP_h_
#define _UDP_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct // Cria uma STRUCT para armazenar os dados de uma pessoa
{
    int sock; 
    int addr_len, bytes_read;
    char recv_data[1024];
    struct sockaddr_in server_addr, client_addr;
} UDP; // Define o nome do novo tipo criado

UDP *UDPSetup(int Port);
char *UDPRead(UDP *udp);

#endif