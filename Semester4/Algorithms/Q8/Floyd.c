/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-04-04 19:32:25 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-04-04 19:47:03
 */

/*
 * Question: Implement Floyd's algorithm for the All-Pairs-Shortest-Paths 
 * problem. Give the trace of this algorithm.
 */

/*
 * Logic: Similar to Warshall's, instead of checking if there is a path (i,j) OR
 * if there is a path (i,k) AND (k,j), we compare the distances between the two 
 * paths above, ie direct path (i,j) and indirect path through k. We assign the 
 * shortest path's value to the node(i,j).
 *
 * Algorithm: Floyd's
 * Time Complexity: O(n^3)
 * Space Complexity: Space complexity: O(1) if we change the original matrix or O
 * (n^2) if we create a new matrix.
 */

#include <stdio.h>

int arr[10][10] = {0};

void floyd(int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (arr[i][j] > (arr[i][k] + arr[k][j]))
                    arr[i][j] = arr[i][k] + arr[k][j];
    // If the new path through k is shorter than the existing path, make the
    // shortest path the new one through k.
}

// You can use a large number to represent infinity or you can use INFINITY in
// math.h if you want to.
int main()
{
    int i, j, n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:-");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    floyd(n);

    printf("The transitive closure is:- \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}