/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-04-27 10:31:23 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-04-08 21:26:22
 */

/*
 * Question: Find Minimum Cost Spanning Tree of a given undirected graph using 
 * Kruskal's algorithm. Give the trace of this algorithm.
 */

/*
 * Explaination: https://www.youtube.com/watch?v=4ZlRH0eK-qQ
 * Logic: Keep picking the shortest edges and as long as an edge is not
 * forming a cycle, continue till all the vertices are covered. This
 * implementation uses priority queue to sort
 * Time complexity: O(vE) = O(n^2)
 * Space complexity: O(n)
 */

#include <stdio.h>
#include <time.h>
struct edge
{
    int node1;
    int node2;
    int len;
} priorityQ[40], result[10];

int priorityFront = -1, priorityRear = -1, resultFront = -1, resultRear = -1;
int priorityLen = 0, resultLen = 0;

void priorityEnqueue(struct edge e) // Enqueue function for the priority queue
{
    int i;
    if (priorityFront == -1)
    {
        priorityFront = 0;
        priorityRear = 0;
        priorityQ[priorityRear].len = e.len;
        priorityQ[priorityRear].node1 = e.node1;
        priorityQ[priorityRear].node2 = e.node2;
        priorityLen++;
        return;
    }

    for (i = priorityRear; i >= 0; i--)
    {
        if (priorityQ[i].len > e.len)
        {
            priorityQ[i + 1] = priorityQ[i];
        }
        else
        {
            break;
        }
    }
    priorityQ[i + 1].len = e.len;
    priorityQ[i + 1].node1 = e.node1;
    priorityQ[i + 1].node2 = e.node2;
    priorityRear++;
    priorityLen++;
}

struct edge priorityDequeue() // Dequeue() for the priority queue
{
    struct edge e;
    e.len = priorityQ[priorityFront].len;
    e.node1 = priorityQ[priorityFront].node1;
    e.node2 = priorityQ[priorityFront++].node2;
    return e;
}

void resultEnqueue(struct edge e) // Enqueue() for the result queue
{
    if (resultFront == -1)
    {
        resultFront = 0;
        resultRear = 0;
        result[resultRear].len = e.len;
        result[resultRear].node1 = e.node1;
        result[resultRear].node2 = e.node2;
        resultLen++;
        return;
    }
    result[++resultRear].len = e.len;
    result[resultRear].node1 = e.node1;
    result[resultRear].node2 = e.node2;
    resultLen++;
}

struct edge resultDequeue() // Dequeue for the result queue
{
    struct edge e;
    e.len = result[resultFront].len;
    e.node1 = result[resultFront].node1;
    e.node2 = result[resultFront++].node2;
    return e;
}

int cyclic(struct edge e) // to check of the edge passed as parameter creates
// a cycle with the existing edges
{
    int i, visited[10] = {0}, counter = 0;
    for (i = 0; i < resultLen; i++)
    {
        visited[result[i].node1] = 1;
        visited[result[i].node2] = 1;
    }
    visited[e.node1] = 1;
    visited[e.node2] = 1;

    for (i = 0; i < 10; i++)
        if (visited[i])
            counter++;

    if (counter >= resultLen + 2)
        return 0;
    return 1;
}

void printResult()
{
    int i, totalCost = 0;
    struct edge e;
    for (i = 0; i < resultLen; i++)
    {
        e = resultDequeue();
        printf("Edge %d: Node %d to Node %d\n", i + 1, e.node1, e.node2);
        totalCost += e.len;
    }
    printf("Total cost: %d\n", totalCost);
}

void kruskal(int adj[][10], int n)
{
    clock_t start = clock();
    int visited[10] = {0}, i, j;
    struct edge e;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++) // j=i+1 for undirected, j=0 for directed
        {
            if (adj[i][j])
            {
                e.node1 = i;
                e.node2 = j;
                e.len = adj[i][j];
                priorityEnqueue(e);
            }
        }
    }

    for (i = 0; i < priorityLen; i++)
    {
        e = priorityDequeue();

        if (!cyclic(e))
        {
            resultEnqueue(e);
        }
        if (resultLen == n - 1)
            break;
    }

    if (resultLen == n - 1)
        printResult();
    else
        printf("No spanning tree could be generated\n");
    printf("%f", ((double)(clock() - start)) / CLOCKS_PER_SEC);
}

int main()
{
    int adj[10][10], n, i, j;

    printf("Enter the no. of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:-\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    kruskal(adj, n);

    return (0);
}
