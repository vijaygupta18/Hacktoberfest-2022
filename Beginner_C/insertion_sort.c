//Program to perform Insertion Sort

#include<stdio.h>

int insertionSort(int arr[], int size);

int main()
{
    int n, count = 0;
    printf("Enter the number of elements in the array:\n");
    scanf("%d",&n);
    int array[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    count = insertionSort(array, n);
    printf("Array after sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\nCount = %d", count);
    return 0;
}

int insertionSort(int arr[], int size)
{
    int i, j, count = 0;
    for(i=1;i<size;i++)
    {
        int key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
            count++;
        }
        arr[j+1] = key;
    }
    return count;
}