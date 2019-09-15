/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-04-27 10:31:23 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-04-27 11:30:22
 */

/*
 * Question: Find Minimum Cost Spanning Tree of a given undirected graph using 
 * Kruskal's algorithm. Give the trace of this algorithm.
 */

/*
 * Explaination: https://www.youtube.com/watch?v=4ZlRH0eK-qQ
 * Logic: Keep picking the shortest edges and as long as an edge is not
 * forming a cycle, continue till all the vertices are covered.
 * This method uses brute force to find the shortest edge
 * Time complexity: O(vE) = O(n^2) but O(n^3) in our case due to adjacency matrix
 * Space complexity: O(n)
 */

#include <stdio.h>
#include <time.h>

void kruskal(int costMatrix[10][10], int n)
{
    clock_t start = clock();
    int a, b, u, v, i, j, noOfEdges = 0, parent[10] = {0}, totalCost = 0;
    int min;

    while (noOfEdges < n - 1)
    {
        min = 1000; // Represents infinity
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (costMatrix[i][j] < min)
                {
                    min = costMatrix[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // To find the originating node of each branch (if any)
        while (parent[u])
            u = parent[u];
        while (parent[v])
            v = parent[v];

        if (u != v) // Means they are acyclic beacause they don't originate from
        // the same parent
        {
            printf("Edge %d: node %d to node %d, cost: %d\n", ++noOfEdges, a, b, min);
            totalCost += min;
            parent[v] = u;
        }
        costMatrix[a][b] = costMatrix[b][a] = 1000;
        // Only change costMatrix[a][b] for directed graph
    }
    printf("The min. cost of the tree is: %d\n", totalCost);
    printf("%f", ((double)(clock() - start)) / CLOCKS_PER_SEC);
}

int main()
{
    int costMatrix[10][10], n, i, j;

    printf("Enter the no. of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:-\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &costMatrix[i][j]);

    kruskal(costMatrix, n);
    return (0);
}
