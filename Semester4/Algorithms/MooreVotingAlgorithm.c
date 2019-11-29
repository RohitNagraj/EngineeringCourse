/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-11-29 09:22:29 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-11-29 09:38:17
 */

/*
 * Question: You are given an array on length n. Find if any element occurs more than n/2 times,
 * if present, return that element, else return -1.
 */

/*
 * Boyer-Moore majority vote algorithm
 * ALgorithn: 
 * findCandidate(a[], size)
 *   maj_index =0, count = 1
 * loop for i = 1 to size-1
 *   if a[maj_index] == a[i]
 *     count++
 *   else
 *     count--
 *   if count == 0
 *     maj_index = i;
 *     count = 1
 *   return a[maj_index]
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

#include <stdio.h>

int moore(int a[], int n)
{
    int count = 0, candidate, i;
    for (i = 0; i < n; i++)
    {
        if (count == 0)
        {
            candidate = a[i];
            count = 1;
        }
        else
        {
            if (a[i] == candidate)
                count++;
            else
                count--;
        }
    }

    if (count > 0)
    {
        count = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] == candidate)
                count++;
        }
        if (count > n / 2)
            return candidate;
    }
    return -1;
}

int main()
{
    int a[20], n, i, res;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    res = moore(a, n);
    if (res == -1)
        printf("There is no majority element\n");
    else
        printf("The majority element is: %d\n", res);
    return (0);
}
