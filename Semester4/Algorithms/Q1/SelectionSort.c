/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-02-05 18:19:22 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-02-13 19:19:59
 */

/* Question:-
 * Sort a given set of elements using bubble and selection sort and determine the time
 * required to sort the elements. Plot a graph of no. of elements vs time taken. 
 * Specify the time efficiency class of this algorithm. 
 */

/*
 * Logic: Take the first element, find the smallest element in the rest of the array,
 * swap it with the first element. Repeat with 2nd element and so on.
 * 
 * Algorithm: Selection Sort
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */

/* Psuedo Code:-
 * 
 * for i from 0 to n-1
 *    small  = i
 * 
 *    for j from i+1 to n
 *       if array[j] < array[small]
 *          small = j
 * 
 *    swap array[small] and array[i]   
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double SelectionSort(int *array, int n)
{
    int i, j, smallest, temp;
    clock_t start = clock();

    for (i = 0; i < n - 1; i++)
    {
        smallest = i;
        for (j = i + 1; j < n; j++) // Loop finds the smallest element from i+1 to n
        {
            if (array[j] < array[smallest])
                smallest = j;
        }

        // Swap the smallest element with the current ith element
        temp = array[i];
        array[i] = array[smallest];
        array[smallest] = temp;
    }

    return ((double)(clock() - start)) / CLOCKS_PER_SEC;
    // Returns the time taken to run the sorting algorithm
}

int main()
{
    int i, n;
    double t;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) // Generate an array with random values
    {
        a[i] = rand() % 1000;
    }
    t = SelectionSort(a, n);
    printf("Time: %fs\n", t);
    return 0;
}

/*
 * Observation:-
 *  X(size of array)    y(time in s)
 *      10,000            0.1708
 *      20,000            0.677
 *      30,000            1.521
 *      40,000            2.702
 *      50,000            4.222
 *      60,000            6.073
 *      70,000            8.274
 *      80,000            10.795
 *      90,000            13.664
 *      100,000           16.878
 * 
 * -> The code runs on a single thread
 */
