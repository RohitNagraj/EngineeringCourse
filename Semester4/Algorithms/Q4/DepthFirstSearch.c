/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-05-27 18:20:48 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-05-27 18:34:36
 */
#include <stdio.h>

int visited[10] = {0};

void dfs(int arr[10][10], int n, int node)
{
    int i;
    visited[node] = 1;
    printf("%d ", node + 1);
    for (i = 0; i < n; i++)
    {
        if (!visited[i] && arr[node][i]) // If a node is connected and not visited, visit it
            dfs(arr, n, i);              // DFS requires a stack to function. Here, we use the system stack itself as we are performing recurssion.
    }
}

int main()
{
    int i, j, arr[10][10], node, n;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    printf("Enter the starting vertex: ");
    scanf("%d", &node);

    printf("The order of search is: ");
    dfs(arr, n, node - 1);
    // Node indexing start from 1
    return (0);
}