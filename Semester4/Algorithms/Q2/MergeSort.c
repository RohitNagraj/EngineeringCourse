/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-02-13 18:38:06 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-02-13 19:27:58
 */

/* Question:-
 * Sort a given set of elements using merge sort and determine the time
 * required to sort the elements. Plot a graph of no. of elements vs time taken. 
 * Specify the time efficiency class of this algorithm. 
 */

/* Logic: Break the given array into smaller subarrays and sort them. Merge 
 * the smaller sorted
 * subarrays in a sorted manner to obtain the sorted array.
 * 
 * Algorithm: Merge Sort
 * Time complexity: O(nlogn)
 * Space complexity: O(n)
 */

/* Psuedo Code:-
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

/* Input: Takes in a pointer to the array, the low, mid, high indices wherein
 * the mid represents the index where the two subarrays to be merged are split.
 * Example: arr = [4,5,1,2,3], low = 0, mid = 2, high = 5
 * 
 * Output: The 2 subarrays are now merged into the same array, now in sorted 
 * order.
 * 
 * Description: It copies the two subarrays into 2 new arrays, then compares the
 * first values of each array and goes on placing them in the original array.
 * Example: leftArray = [4,5], rightArray = [1,2,3]. It compares the smallest
 * elements and places the smaller one in the original array.
 */
void merge(int *arr, int low, int mid, int high)
{
    int i, j, k;
    int N1 = mid - low;  // Left half in the array's size
    int N2 = high - mid; // Size of right half

    int leftArray[N1], rightArray[N2];

    for (i = 0, j = low; j < mid; i++, j++) // Copies left half of arr to leftArray
        leftArray[i] = arr[j];

    for (i = 0, j = mid; j < high; i++, j++) // Copies right half of arr to rightArray
        rightArray[i] = arr[j];

    i = 0;
    j = 0;
    k = low;

    while (i < N1 && j < N2) // As long as there are elements in both arrays
    {
        if (leftArray[i] < rightArray[j])
            arr[k++] = leftArray[i++]; // Put smaller element into arr and increment both their counters

        else
            arr[k++] = rightArray[j++];
    }

    while (i < N1) // Empty any remaining elements in leftArray (case when right array is exhausted and left array still contains elements)
        arr[k++] = leftArray[i++];

    while (j < N2) // Empty the rightArray
        arr[k++] = rightArray[j++];
}

double mergeSort(int *arr, int low, int high)
{
    int mid = (low + high) / 2;

    if (high - low == 1) // Base condition: only 1 element
        return arr[low];

    clock_t start = clock();

    mergeSort(arr, low, mid);  // Sorts left half
    mergeSort(arr, mid, high); // Sorts right half

    merge(arr, low, mid, high); // Merges left and right half in sorted manner

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
        a[i] = rand() % 1000;

    t = mergeSort(a, 0, n);

    printf("Time: %fs\n", t);
    return 0;
}

/*
 * Observation:-
 *  X(size of array)    y(time in s)
 *      10,000            0.020275
 *      20,000            0.037451
 *      30,000            0.054474
 *      40,000            0.070230
 *      50,000            0.088091
 *      60,000            0.103341
 *      70,000            0.120484
 *      80,000            0.139971
 *      90,000            0.157736
 *      100,000           0.171292
 * 
 * -> The code runs on a single thread
 */
