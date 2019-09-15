/*
 * @Author: Rohit Nagraj 
 * @Date: 2019-02-14 20:12:18 
 * @Last Modified by: Rohit Nagraj
 * @Last Modified time: 2019-02-14 20:24:01
 */

/* Question:-
 * Sort a given set of elements using heap sort and determine the time
 * required to sort the elements. Plot a graph of no. of elements vs time taken. 
 * Specify the time efficiency class of this algorithm. 
 */

/* Logic: Create a max heap, place the element obtained at the end of the array,
 * reduce the size of the array and repeat.
 * 
 * Algorithm: Heap Sort
 * Time complexity: O(nlogn)
 * Space complexity: O(1)
 */

/* Psuedo Code:-
 * maxHeapify(A,i)
 *   l = leftChild(i)
 *   r = rightChild(i)
 * 
 *   if l<A.heapSize and A[l] > A[i]
 *     largest = l
 *   else largest  = i
 * 
 *   if r <= A.heapSize and A[r] > A[largest]
 *     largest = r
 *   
 *   if largest != i
 *     swap A[i] and A[largest]
 *     maxHeapify(A, largest)
 * 
 * buildMaxHeap(A)
 *   A.heapSize = A.length
 *   for i from floor(A.length/2) downto 0
 *     maxHeapify(A,i)
 * 
 * heapSort(A)
 *   buildMaxHeap(A)
 *   for i from A.length downto 1
 *     swap A[0] with A[i]
 *     A.heapSize = A.heapSize-1
 *     maxHeapify(A,0)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getLeftChild(int *a, int n, int index)
{
    return a[(index * 2) + 1];
}

int getRightChild(int *a, int n, int index)
{
    return a[(index * 2) + 2];
}

int getLeftChildIndex(int *a, int n, int index)
{
    return (index * 2) + 1;
}

int getRightChildIndex(int *a, int n, int index)
{
    return (index * 2) + 2;
}

int hasLeftChild(int *a, int n, int index)
{
    if ((index * 2) + 1 < n)
        return 1;
    return 0;
}

int hasRightChild(int *a, int n, int index)
{
    if ((index * 2) + 2 < n)
        return 1;
    return 0;
}

int hasParent(int *a, int n, int index)
{
    if ((index - 1) / 2 >= 0)
        return 1;
    return 0;
}

int getParent(int *a, int n, int index)
{
    return a[(index - 1) / 2];
}

int getParentIndex(int *a, int n, int index)
{
    return (index - 1) / 2;
}

void swap(int *a, int i1, int i2)
{
    int t = a[i1];
    a[i1] = a[i2];
    a[i2] = t;
}

void heapifyDown(int *a, int n, int index)
{
    int largest;
    while (hasLeftChild(a, n, index))
    {
        largest = index;
        if (getLeftChild(a, n, index) > a[largest])
            largest = getLeftChildIndex(a, n, index);
        if (hasRightChild(a, n, index))
            if (getRightChild(a, n, index) > a[largest])
                largest = getRightChildIndex(a, n, index);

        if (index == largest)
            break;

        swap(a, index, largest);
        index = largest;
    }
}

void buildMaxHeap(int *a, int n)
{
    int i;
    for (i = n/2; i >= 0; i--)
        heapifyDown(a, n, i);
}

void heapSort(int *a, int n)
{
    int i, t = n;
    buildMaxHeap(a, n);
    for (i = n - 1; i > 0; i--)
    {
        swap(a, 0, i);
        heapifyDown(a, --t, 0);
    }
}

int main()
{
    int i, n, a[100];
    double t;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
            scanf("%d", &a[i]);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    heapSort(a, n);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
