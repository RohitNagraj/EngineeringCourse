// Mergesort
#include <stdio.h>

void merge(int *arr, int start, int mid, int end)
{
    int n1[mid - start], n2[end - mid], i, j, k;
    i = 0;
    j = start;

    while (j < mid)
        n1[i++] = arr[j++];

    i = 0;
    k = mid;
    while (k < end)
        n2[i++] = arr[k++];

    i = 0;
    j = 0;
    k = start;
    while (i < mid - start && j < end - mid)
    {
        if (n1[i] < n2[j])
        {
            arr[k++] = n1[i++];
        }
        else
            arr[k++] = n2[j++];
    }
    while (i < mid - start)
        arr[k++] = n1[i++];
    while (j < end - mid)
        arr[k++] = n2[j++];
}

void mergeSort(int *arr, int start, int end)
{
    int mid;
    if (end - start > 1)
    {
        mid = (end + start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[10], n, i;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return (0);
}