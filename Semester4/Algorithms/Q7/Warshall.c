/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-04-04 18:44:31 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-04-04 19:39:16
 */

/*
 * Question: Compute the transitive closure of a given directed graph using 
 * Warshall's algorithm. Give the trace of this algorithm.
 */

/*
 * Logic: Assume 1 represents a path present and 0 represents an absence of a
 * path between 2 nodes in the adjacency matrix. If any non-existant path can be
 * created between 2 nodes by passing through another vertex, that path is 
 * created and its value in the adjacency matrix is made 1.
 * Algorithm: Warshall's
 * Time compexity: O(n^3)
 * Space complexity: O(1) if we change the original matrix or O(n^2) if we 
 * create a new matrix.
 */

#include <stdio.h>

int arr[10][10] = {0};

void warshall(int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                arr[i][j] = arr[i][j] || (arr[i][k] && arr[k][j]);
    // If the path (i,j) is already present OR if there is a path between (i,k)
    // AND (k,j).
}

int main()
{
    int i, j, n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:-");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    warshall(n);

    printf("The transitive closure is:- \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}