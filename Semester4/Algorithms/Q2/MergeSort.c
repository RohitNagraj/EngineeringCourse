/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-02-05 18:19:22 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-02-05 18:43:38
 */

/** Question:-
 * Sort a given set of elements using merge sort and determine the time
 * required to sort the elements. Plot a graph of no. of elements vs time taken. 
 * Specify the time efficiency class of this algorithm. 
 */

/**
 * Logic: Break the given array into smaller subarrays and sort them. Merge the smaller sorted
 * subarrays in a sorted manner to obtain the sorted array.
 * Algorithm: Merge Sort
 * Time complexity: O(nlogn)
 * Space complexity: O(n)
 */

/** Psuedo Code:-
 * 
 * merge(a, low, mid, high)
 *   b = []
 *   i = low
 *   j = mid
 * 
 *   for k from low upto high
 *     if a[i] < a[j]
 *       b[k++] = a[i++]
 *     else
 *       b[k++] = a[j++]
 *   return b
 *  
 * mergeSort(arr, low, high)
 *   if(high == low)
 *     return a[low]
 * 
 *   mid = floor((low + high) / 2)   
 *   mergeSort(arr, low, mid)
 *   mergeSort(arr, mid+1, high)
 * 
 *   arr = merge(arr, low, mid, high)   
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *arr, int low, int mid, int high)
{
    int i,j,k;
    int N1 = mid - low + 1;
    int N2 = high - mid;

    int leftArray[N1] , rightArray[N2];

    for(i = 0, j = low; j< mid; i++, j++)
        leftArray[i] = arr[j];

    for(i = 0, j = mid; j < high; i++, j++)
        rightArray[i] = arr[j];

    i = 0;
    j = 0;
    for(k = low; k < high; k++)
    {
        if(leftArray[i] < rightArray[j])
            arr[k++] = leftArray[i++];
        else
            arr[k++] = rightArray[j++];
    }

    if(i != N1)
    {
        for(; i< N1; i++)
            arr[k++] = leftArray[i++];
    }

    else
    {
        for(; j< N2; j++)
            arr[k++] = rightArray[j++];
    }
}

double mergeSort(int *arr, int low, int high)
{
    int mid = (low + high)/2;

    if(high-low == 1)
        return arr[low];

    clock_t start = clock();

    mergeSort(arr, low, mid);
    mergeSort(arr, mid, high);
    
    merge(arr, low, mid, high);

    return ((double)(clock() - start)) / CLOCKS_PER_SEC;
    // Returns the time taken to run the sorting algorithm
}

int main()
{
    // int i, n;
    // double t;
    // printf("Enter the size of the array: ");
    // scanf("%d", &n);
    // int a[n];
    // for (i = 0; i < n; i++) // Generate an array with random values
    // {
    //     a[i] = rand() % 1000;
    // }
    // t = mergeSort(a, 0, n);
    // printf("Time: %fs\n", t);
    // return 0;

    int i, a[] = {4,5,1,2,3};
    merge(a, 0, 2, 5);
    for(i = 0; i<5;i++)
    printf("%d", a[i]);
}

/**
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
