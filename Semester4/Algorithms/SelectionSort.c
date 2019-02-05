/** Question:-
 * Sort a given set of elements using bubble and selection sort and determine the time
 * required to sort the elements. Plot a graph of no. of elements vs time taken. 
 * Specify the time efficiency class of this algorithm. 
 */


/**
 * Algorithm: Selection Sort
 * Time complexity: O(n^2)
 */


/** Input-Output:-
 * Input: A 1D array as the first argument and its length as the 2nd argument
 * Output: None
 * description: The input array is modified and at the end of the function, the array will be sorted.
 */


/** Psuedo Code:-
 * for(i=0, i<n-1; i++)
 *    small  = i
 * 
 *    for(j=i+1; j<n; j++)
 *       if(array[j] < array[small])
 *          small = j
 * 
 *    swap small and array[i]   
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100000

double SelectionSort(int *array, int n)
{
    int i,j,smallest, temp;
    clock_t start = clock();

    for(i =0; i < n-1; i++)
    {
        smallest = i;
        for(j = i+1; j < n; j++)
        {
            if(array[j] < array[smallest])
                smallest = j;
        }

        temp = array[i];
        array[i] = array[smallest];
        array[smallest] = temp;
    }

    return ((double)(clock()-start))/CLOCKS_PER_SEC;
}

int main()
{
    int i;
    double t;
    int a[SIZE];
    for(i = 0;i<SIZE; i++)
    {
        a[i] = rand()%1000;
    }
    t = SelectionSort(a,SIZE);
    for(i = 0;i<6;i++)
        printf("%d\n", a[i]);
    printf("Time: %fs\n", t);
    return 0;
}