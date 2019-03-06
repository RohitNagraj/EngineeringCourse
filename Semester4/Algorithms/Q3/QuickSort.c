/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-02-19 15:53:35 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-03-06 19:25:26
 */

/* Question:-
 * Sort a given set of elements using quicksort and determine the time
 * required to sort the elements. Plot a graph of no. of elements vs time taken. 
 * Specify the time efficiency class of this algorithm. 
 */

/* Explaination: https://www.youtube.com/watch?v=COk73cpQbFQ
 * 
 * Logic: Pick a pivot element, re-arrange the array such that all the elements
 * to the left of it are smaller than it, and all the elements to the right are
 * larger. Then apply quicksort to the left part and the right part.
 * 
 * Algorithm: Quicksort
 * Time complexity: O(nlogn)
 * Space complexity: O(1)
 */

/* Pseudo Code:-
 * 
 * partition(arr, low, high)
 *   pivot = arr[high]
 *   pivotIndex = low
 *   for i from low to high-1
 *     if arr[i] < pivot
 *       swap arr[i] and arr[pivotIndex]
 *       pivotIndex++
 *   swap arr[pivotIndex] and arr[high]
 * 
 * quickSort(arr, low, high)
 *   if(high > low)
 *     pivotIndex = partition(arr, low, high)
 *     quickSort(arr, low, partition)
 *     quickSort(arr, partition+1, low)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *arr, int x, int y)
{
    int t = arr[x];
    arr[x] = arr[y];
    arr[y] = t;
}

int partition(int *arr, int low, int high)
{
    // This implementation considers the pivot at the end. Watch the above linked
    // video to get a clear explaination.

    int pivot = arr[high - 1]; // Last element
    int pivotIndex = low, i;
    // pivotIndex represents the index from where elements that are greater than
    //pivot start. Its initially considered 0.

    for (i = low; i < high - 1; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr, i, pivotIndex);
            pivotIndex++;
            // Any element less than pivot will be
            // swapped with pivotIndex element (first largest element) and
            // pivotIndex is incremented.
            // Thus, pivotIndex continues to keep track of the first, larger than
            // pivot, element in the array.
        }
    }
    swap(arr, high - 1, pivotIndex);
    return pivotIndex;
    // This swaps the first element larger than pivot with the pivot itself at
    //the end, thus giving the required partitioned array.
}

double quickSort(int *arr, int low, int high)
{
    int pivotIndex;

    clock_t start = clock();

    if (high - low > 1)
    {
        pivotIndex = partition(arr, low, high); // Partition the array and get its pivot index
        quickSort(arr, low, pivotIndex);        // Sort left part
        quickSort(arr, pivotIndex + 1, high);   // Sort right part
    }
    return ((double)(clock() - start)) / CLOCKS_PER_SEC;
}

int main()
{
    int i, n;
    double t;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];

    for (i = 0; i < n; i++)   // Generate an array with random values
        a[i] = rand() % 1000; // % ensures all the random values are in range 0-1000

    t = quickSort(a, 0, n);

    printf("Time: %fs\n", t);
    return 0;
}

/*    for (i = 0; i < 10; i++)
 * Observation:-
 *  X(size of array)    y(time in s)
 *      10,000            0.031143
 *      20,000            0.060971
 *      30,000            0.090433
 *      40,000            0.121691
 *      50,000            0.153758
 *      60,000            0.184391
 *      70,000            0.215080
 *      80,000            0.245797
 *      90,000            0.282257
 *      100,000           0.311258
 * 
 * -> The code runs on a single thread
 */
