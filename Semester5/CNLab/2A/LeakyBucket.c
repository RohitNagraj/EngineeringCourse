/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-11-25 00:22:05 
 * @Last Modified by:   Rohit Nagraj 
 * @Last Modified time: 2019-11-25 00:22:05 
 */
#include <stdio.h>
#include <stdlib.h>
#define min(a, b) (a < b) ? a : b
#define max(a, b) (a > b) ? a : b
/*
input: Array of incoming no. of packets
output: max no. of packets the router can send at once
capacity: buffer size of the router
n: no. of iterations for inputs
*/
void leakyBucket(int input[], int output, int capacity, int n)
{
    int i, j;
    int recieved, sent, dropped, buffered = 0;

    printf("Time\tRecieved\tSent\tBuffered\tDropped\n");
    // If there is data in the buffer, loop continues
    for (i = 0; i < n || buffered != 0; i++)
    {
        // If data incoming, recieve it and add it to the buffer
        if (i < n)
            recieved = input[i];
        else
            recieved = 0;

        buffered += recieved;

        // Sending will be limited to the availability of packets and output capacity of the bucket
        // Whichever is lower
        sent = min(buffered, output);

        // Once sent, it is removed from the buffer
        buffered -= sent;

        // If the buffer exceeds capacity, packets are dropped and buffer remains full
        dropped = max(buffered - capacity, 0);
        if (dropped)
            buffered = capacity;

        printf("%d\t   %d\t\t  %d\t   %d\t\t   %d\n", i, recieved, sent, buffered, dropped);
    }
}

int main()
{
    int input[20], output = 2, capacity = 5, n = 10, i;
    for (i = 0; i < n; i++)
        input[i] = rand() % 10;
    leakyBucket(input, output, capacity, n);
    return (0);
}