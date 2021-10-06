#include <stdio.h>
#include <math.h>
void insertionSort(int arr[], int n)
{
	int i, k, j;
	for (i = 1; i < n; i++) 
	{
		k = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > k) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = k;
	}
}
void printArray(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
int main()
{
	int a[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(a) / sizeof(a[0]);
	insertionSort(a, n);
	printArray(a, n);
	return 0;
}
