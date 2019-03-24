/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-03-06 19:16:39 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-03-06 19:46:26
 */

/*
 * Question: Print all the nodes reachable from a given starting node in a 
 * digraph using BFS. Give the trace of this
 * algorithm.
 */

/*
 * Logic: Take the root node, check all the childs who are connected with this
 * node, if they are not visited, add them to the queue. Call the function
 * recursively on the queue elements.
 * Algorithm: Breadth First Search
 * Time complexity: O(V)
 * Space complexity: O(V)
 */

/*
 * Pseudo code:-
 * create empty queue
 * create boolean array isVisited
 * bfs(node)
 *   mark node as visited
 *   check all the nodes connected to the current node, if any of them are not
 *   visited, add them to queue.
 *   if queue is not empty, call bfs in the first queue element
 */

#include <stdio.h>
#include <stdlib.h>

int matrix[20][20], q[20], isVisited[20] = {0}; // Matrix is the adjacency matrix
// of the graph, isVisited is a boolean array with all values false initially.
int front = -1, rear = -1, n;

void enqueue(int x)
{
    if (front == -1)
    {
        front = 0;
        rear = 0;
        q[front] = x;
        return;
    }
    q[++rear] = x;
}

int dequeue()
{
    return q[front++];
}

int qLength()
{
    return rear - front + 1;
}

void bfs(int node) // Node is the current root node
{
    int i;
    isVisited[node] = 1; // mark root as visited

    for (i = 0; i < n; i++)
        if (matrix[node][i] == 1 && !isVisited[i])
            enqueue(i); // If any node is connected
                        // the root node and it is not visited, enqueue it.

    if (qLength())
        bfs(dequeue());
}

int main()
{
    int i, j, node;

    printf("Enter no. of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:-\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    printf("Enter the starting node: ");
    scanf("%d", &node);

    bfs(node);

    printf("The nodes that can be visited are: ");
    for (i = 0; i < n; i++)
        if (isVisited[i] == 1)
            printf("%d ", i);
    // Nodes start from 0

    printf("\n");
    return (0);
}

/*
 * Output:-
 * Enter no. of nodes: 3
 * Enter adjacency matrix:-
 * 0 1 0
 * 0 0 1
 * 0 1 1
 * Enter the starting node: 1
 * The nodes that can be visited are: 1 2
 */
