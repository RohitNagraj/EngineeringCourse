/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-04-04 20:16:54 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-04-04 20:28:43
 */

/*
 * Question: Implement 0/1 Knapsack problem using dynamic programming. Give the
 * trace of this algorithm.
 */

/*
 * Explaination: https://www.youtube.com/watch?v=nLmhmB6NzcM
 * 
 * Logic: Go on checking 1 item at a time. If adding the current item with the
 * configuration of the previous items such that it had enough space to fit the
 * current item maximizes the profit, add the current item, otherwise keep the
 * previous configuration.
 * Algorithm: Knapsack
 * Time complexity: O(nW), n = no. of items, W = weight of sack
 * Space complexity: O(nW)
 */

#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Item indexing starts from 1
int *knapsack(int n, int maxCapacity, int *weight, int *profit)
{
    int table[n + 1][maxCapacity + 1], i, c, w, selected[n + 1], sum = 0;

    // Making the first row 0
    for (i = 0; i <= maxCapacity; i++)
        table[0][i] = 0;

    // Making the first column 0
    for (i = 0; i <= n; i++)
        table[i][0] = 0;

    for (i = 1; i <= n; i++)
    {
        for (c = 1; c <= maxCapacity; c++)
        {
            if (c >= weight[i]) // If theres enough space in the sack to fit the current item
                table[i][c] = max(table[i - 1][c], table[i - 1][c - weight[i]] + profit[i]);
            else
                table[i][c] = table[i - 1][c];
        }
    }

    for (i = 0; i <= n; i++)
        selected[i] = 0;

    i = n;
    c = maxCapacity; // Last cell
    while (i > 0 && c > 0)
    {
        // If there is a change in the table value from its upper value,
        // that means this change has occured due to that particular item being
        // included. So we track the changes made from the last, that gives us
        // the items that were added at the latest.
        if (table[i][c] != table[i - 1][c])
        {
            selected[i] = 1;
            c -= weight[i];
        }
        i--;
    }

    printf("The selected items are: ");
    for (i = 1; i <= n; i++)
        if (selected[i])
        {
            printf("%d, ", i);
            sum += profit[i];
        }
    printf("\nThe total profit is: %d\n", sum);
}

int main()
{
    int n, maxCapacity, weight[10], profit[10], i, *result;

    printf("Enter no. of items: ");
    scanf("%d", &n);

    printf("Enter the weights of the iems:-\n");
    for (i = 1; i <= n; i++)
    {
        printf("Item %d: ", i);
        scanf("%d", &weight[i]);
    }

    printf("Enter the profits of the items:-\n");
    for (i = 1; i <= n; i++)
    {
        printf("Item %d: ", i);
        scanf("%d", &profit[i]);
    }

    printf("Enter max capacity: ");
    scanf("%d", &maxCapacity);

    knapsack(n, maxCapacity, weight, profit);

    return (0);
}