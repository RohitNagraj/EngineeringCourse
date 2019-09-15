#include<stdio.h>
void BinarySearch(int arr[], int low, int high, int num)
{
	int mid = (high + low)/2;
	if(arr[mid] == num)
		printf("The position of the element in sorted array is: %d\n", mid + 1);

	else if(mid == high)
		printf("The element doesn't exist in the array\n");

	else if(arr[mid] < num)
		BinarySearch(arr, mid+1, high, num);

	else
		BinarySearch(arr, low, mid-1, num);
}

void insertionSort(int arr[], int n) 
{ 
   int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1; 
 
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   }
}

int main()
{
	int size, searchElement, i, arr[20];
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	printf("Enter the elements: ");
	for(i = 0;i<size;i++)
		scanf("%d", &arr[i]);
	insertionSort(arr, size);
	printf("Enter the element to search for: ");
	scanf("%d", &searchElement);
	BinarySearch(arr, 0, size-1, searchElement);
}