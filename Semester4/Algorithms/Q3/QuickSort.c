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

int swap(int *arr, int x, int y)
{
    int t = arr[x];
    arr[x] = arr[y];
    arr[y] = t;
}

int partition(int *arr, int low, int high)
{
    int mid = (low+high)/2;
    int pivot = arr[mid];
    int i, j, k;

    i = low;
    j = high;
    
    while(i < j)
    {
        while(arr[i] < pivot)
            i++;
        
        while(arr[j] > pivot)
            j--;
        
        if(arr[i] > arr[j])
            swap(arr, i, j);
    }

    return j;
}

double quickSort (int *arr, int low, int high)
{

    if(high - low > 1)
    {
    int pivot = partition(arr, low, high);
    
    quickSort(arr, low, pivot);
    quickSort(arr, pivot, high);
    }

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

    t = quickSort(a, 0, n-1);

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
