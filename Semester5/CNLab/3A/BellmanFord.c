/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-11-25 00:30:18 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-11-25 00:33:51
 */

/*
 * Bellman Ford's algorithm gives shortest path to all nodes from the source node. It uses a 
 * dynamic programming approach.
 * Logic: Check for each edge, if going through it will reduce the cost to reach the destination
 * from its previous cost or not? If yes, update it.
 */

/*
 * Time Complexity: O(V*E)
 * Space complexity: O(V+E)
 */

#include <stdio.h>
#include <stdlib.h>

#define INFINITY 100

struct edge
{
    int src, dest, cost;
};

int main()
{
    // edges is a list of all edges, edgeCounter keeps track of the total no. of edges
    int v, i, j, n, costMatrix[20][20], edgeCounter = 0;
    struct edge edges[50];

    printf("Enter the no. of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &costMatrix[i][j]);
            // If an edge exists, add it to the list of edges
            if (i != j && costMatrix[i][j] != INFINITY)
            {
                edges[edgeCounter].src = i;
                edges[edgeCounter].dest = j;
                edges[edgeCounter].cost = costMatrix[i][j];
                edgeCounter++;
            }
        }
    }

    int distance[20];
    printf("Enter source: ");
    scanf("%d", &v);
    v--; // This is because nodes start from 1 for the user whereas we start indexing from 0

    // Set initial distances
    for (i = 0; i < n; i++)
    {
        if (i != v)
            distance[i] = INFINITY;
        else
            distance[i] = 0;
    }

    // Relaxation of distances n-1 times where n in the no. of nodes
    for (i = 0; i < n - 1; i++)
    {
        // We take each edge, and check if it reduces the distance to destination or not
        for (j = 0; j < edgeCounter; j++)
        {
            if (distance[edges[j].src] + edges[j].cost < distance[edges[j].dest])
            {
                distance[edges[j].dest] = distance[edges[j].src] + edges[j].cost;
            }
        }
    }

    printf("The distances from source to all other nodes are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d to %d costs %d\n", v, i + 1, distance[i]);
    }

    return (0);
}