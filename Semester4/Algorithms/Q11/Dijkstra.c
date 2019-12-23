/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-04-27 14:00:09 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-04-27 15:17:25
 */

/*
 * Find the shortest paths to all the vertices from a given vertex using
 * Dijkstra's algorithm.
 */
/* 
 * Explaination:https://www.youtube.com/watch?v=XB4MIexjvY0
 * Logic: Take the starting vertex, find all the paths to it. Take the next 
 * shortest vertex and see if any of the remaining vertices have a shorter 
 * path. Repeat for all vertices.
 *
 * Time Complexity: O(n^2)
 * Space complexity: O(n)
 */

#include <stdio.h>
#define INFINITY 10000

int minDistance(int distance[], int visited[], int n)
// Returns the index of the vertex that is closest but not visited
{
    int minValue = INFINITY, min_index, i;

    for (i = 0; i < n; i++)
        if (!visited[i] && distance[i] <= minValue)
            minValue = distance[i], min_index = i;

    return min_index;
}

int printSolution(int distance[], int n)
{
    int i;
    printf("\nVertex   Distance from Source\n");
    for (i = 0; i < n; i++)
        printf("  %d\t\t%d\n", i, distance[i]);
}

void dijkstra(int cost[][10], int n, int start)
{
    int distance[10], visited[10], i, j, min;
    // Distance holds the distances of the nodes from starting node
    // visited is a bool array to tell if the node is visited or not

    for (i = 0; i < n; i++)
        distance[i] = INFINITY, visited[i] = 0;

    distance[start] = 0; // Distance of starting node to itself

    for (i = 0; i < n - 1; i++) // N-1 because no. of edges = no. of nodes - 1
    {
        min = minDistance(distance, visited, n); // Gets the next closest vertex

        visited[min] = 1;

        for (j = 0; j < n; j++)
            if (!visited[j] && cost[min][j] && distance[min] != INFINITY &&
                distance[min] + cost[min][j] < distance[j]) // Relaxation
                distance[j] = distance[min] + cost[min][j];
    }
    printSolution(distance, n);
}

int main()
{
    int n, cost[10][10], i, j, start;

    printf("Enter the no. of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:-\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    dijkstra(cost, n, start);
    return (0);
}
