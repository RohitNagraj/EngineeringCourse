/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-04-08 21:19:23 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-04-08 21:26:22
 */

/*
 * Question: Find Minimum Cost Spanning Tree of a given undirected graph using 
 * Prim's algorithm. Give the trace of this algorithm.
 */

/*
 * Explaination: https://www.youtube.com/watch?v=4ZlRH0eK-qQ
 * Logic: Pick the first vertex, pick its closest vertex, now pick the closest
 * vertex to either of the two and repeat. So you are connecting the closest
 * vertex each time to build out the MST.
 * Time complexity: O(vE) = O(n^2)
 * Space complexity: O(n)
 */

#include <stdio.h>
#include <stdlib.h>

int minKey(int *key, int *tree, int n)
{
    // Returns the vertex with minimum key and not in tree.
    int min_key = 32000, min_index, i;
    for (i = 0; i < n; i++)
    {
        if (key[i] < min_key && !tree[i])
        {
            min_index = i;
            min_key = key[i];
        }
    }
    return min_index;
}

void printTree(int *parent, int graph[][10], int n)
{
    int i;
    for (i = 1; i < n; i++) // Starts from 1 because first vertex has no parent
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void prim(int graph[][10], int n)
{
    int i, j, k;
    int tree[10] = {0}, key[10] = {0}, parent[10] = {0};
    // tree contains the current set of vertices in the tree
    // keys contains the shortest edge to a vertex already present in the tree.
    // Parent will represent the constructed MST.

    for (i = 0; i < n; i++)
        key[i] = 32000; // Represents infinity

    // Making the first vertex reachable
    key[0] = 0;     // So the minKey() can pick the first vertex.
    parent[0] = -1; // Since first vertex doesn't have any parent

    for (i = 0; i < n - 1; i++) // n-1 because there will be n-1 edges
    {
        k = minKey(key, tree, n); // Returns the vertex closest to the current
        // tree. Thus, k represents the closest vertex.

        tree[k] = 1; // Include that vertex in the tree

        for (j = 0; j < n; j++) // This loop finds the closest adjacent vertix to
        // the newly added vertex k which is not already in the tree.
        {
            if (graph[k][j] && !tree[j] && graph[k][j] < key[j])
            {
                key[j] = graph[k][j];
                parent[j] = k;
            }
        }
    }

    printTree(parent, graph, n);
}

int main()
{
    int graph[10][10], i, j, n;
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix of the graph:-\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    prim(graph, n);
    return (0);
}