/**
 * @file UDP.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief 
 * 
 */
typedef struct // Cria uma STRUCT para armazenar os dados de uma pessoa
{
    int sock;
    int addr_len, bytes_read;
    char recv_data[1024];
    struct sockaddr_in server_addr, client_addr;
} UDP; // Define o nome do novo tipo criado

/**
 * @brief 
 * 
 */
UDP InitUDP(int Port);

/**
 * @brief 
 * 
 */
void ReadUDP(UDP udp);