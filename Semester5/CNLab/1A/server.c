/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-11-25 00:21:51 
 * @Last Modified by:   Rohit Nagraj 
 * @Last Modified time: 2019-11-25 00:21:51 
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
    int server, client, n;         // Both client and socket are instances of the socket object
    char buffer[buffersize];       // buffer will be used to read data temporarily
    struct sockaddr_in serverAddr; // delacaration of the sockaddr_in structure
    // defined in socket.h, which has 4 initialization parameters

    char fname[20];
    struct sockaddr_storage serverStorage; // Used to store data of the client
    socklen_t addr;                        // Stores the address of the serverStorage

    /*
    Create a new socket instance. 3 parameters are:
    1. Address domain: AF_INET: Address family IPv4
    2. Type of data to send: SOCK_STREAM: Sequenced, reliable, connection-based byte streams
    3. Protocol: 0 means pick automatically, TCP in this case since we need a reliable connection
    */
    server = socket(AF_INET, SOCK_STREAM, 0);

    /*
    A socket server address has the 4 following parts
    1. sin_addr.s_addr: The actual IPv4 address where the server runs
    2. sin_family: To what family the above address belongs to, AF_INET means IPv4
    3. sin_port: On which port should the server run on, 5000 in this case.
    htons function converts from hex to network data, taking care of different endian
    formats and making sure the correct network address is produced.
    4. sin_zero: This is used as a padding to match the size of struct sockaddr which
    is actually used by other functions, thus sockaddr_in is casted to sockaddr and passed
    over to other functions.
    memset sets sin_zero to 0 in one go.
    */
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5000);
    memset(serverAddr.sin_zero, 0, sizeof(serverAddr.sin_zero));

    // Bind connects the socket object with the server address
    // sockaddr_in object is casted to sockaddr and passed over, making use of polymorphism.
    bind(server, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    // 5 connection requests will be queued before refusing any more
    if (listen(server, 5) == 0)
        printf("Listening\n");
    else
        printf("Error\n");

    addr = sizeof(serverStorage);

    // When a new client arrives, its details is stored in serverStorage object.
    client = accept(server, (struct sockaddr *)&serverStorage, &addr);

    // recieve 255 bytes of data into fname from client with no (0) flags set
    recv(client, fname, 255, 0);
    printf("Accessing %s\n", fname);

    // open returns a file pointer
    if (open(fname, O_RDONLY) == -1)
    {
        strcpy(buffer, "FILE NOT FOUND!");
        n = strlen(buffer);
    }
    else
    {
        // read from the opened file into the buffer, a chunk of size=buffersize.
        n = read(open(fname, O_RDONLY), buffer, buffersize);
    }
    // Send the n bytes of data read to the client with no (0) flags
    send(client, buffer, n, 0);
    close(client);
    return close(server);
}