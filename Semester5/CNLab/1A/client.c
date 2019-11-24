/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-11-25 00:21:44 
 * @Last Modified by:   Rohit Nagraj 
 * @Last Modified time: 2019-11-25 00:21:44 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define buffersize 1024

int main()
{
    int client, server;                 // Both are instances of the socket object
    char buffer[buffersize], fname[25]; // buffer will be used to read data temporarily
    struct sockaddr_in serverAddr;      // delacaration of the sockaddr_in structure
    // defined in socket.h, which has the following 4 initialization parameters

    // A internet socket address has 4 parameters
    // 1. server address on which it is hosted. 127.0.0.1 is called loopback
    // address, it refers to the same network card that it is running,
    // basically referring to the same machine.
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 2. Server address family: Which family does the above address belong to
    // AF_INET means Address Family - IPv4
    serverAddr.sin_family = AF_INET;

    // 3. Server port address: The port on which the server should run
    // htons converts hex to network. Which means it takes care of endian and
    // creates the correct network address by taking endian into consideration
    serverAddr.sin_port = htons(5000);

    // 4. memset sets a particular memory location to a value.
    // First parameter is the address of where to set the values, 2nd is what
    // value to set, 3rd is for how much size.
    // serverAddr.sin_zero is the padding given to the sockaddr_in struct so
    // it matches the size of struct sockaddr which it will be casted to later
    memset(serverAddr.sin_zero, 0, sizeof(serverAddr));

    // The socket function returns an integer referring to the socket object
    // The client creates its own socket object and then connects to the server
    // Domain: AF_INET: Address family - IPv4
    // Type: SOCK_STREAM: Sequenced, reliable, connection-based byte streams
    // Protocol: 0 means pick protocol automatically
    // can also be written as client = socket(2,1,0);
    client = socket(AF_INET, SOCK_STREAM, 0);

    // Connect the client socket to the server running on serverAddr
    connect(client, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    printf("Connected to server\n");

    printf("\nEnter filename: ");
    scanf("%s", fname);

    // 255 is the no. of bytes of buffer sent to the server
    send(client, fname, 255, 0);

    // While there's data coming in, copy it to buffer and print it.
    while ((recv(client, buffer, 255, 0)) > 0)
        printf("%s", buffer);
    printf("\n");
    return close(client);
}
