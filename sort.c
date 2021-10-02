// all sorting algorithms

//BUBBLE SORT
#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Bubble(int A[],int n)
{
    int i,j,flag=0;

    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0)break;
    }

}

// Insertion sort

#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Insertion(int A[],int n)
{
    int i,j,x;

    for(i=1;i<n;i++)
    {
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

// selection sort

#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void SelectionSort(int A[],int n)
{
    int i,j,k;

    for(i=0;i<n-1;i++)
    {
        for(j=k=i;j<n;j++)
        {
            if(A[j]<A[k])k=j;
        }
        swap(&A[i],&A[k]);
    }
}

// quick sort

#include<stdio.h>
void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main(){
   int i, count, number[25];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);

   quicksort(number,0,count-1);

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}

// Iterative merge sort
void merge(int A[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    int B[100];
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j]){
        B[k++]=A[i++];
        }
        else{
            B[k++]=A[j++];
        }
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];
    for(i=l;i<=h;i++)
        A[i]=B[i];
}
void IMergeSort(int A[],int n)
{
    int p,l,h,mid,i;
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2; 
            merge(A,l,mid,h);
        }
        if(n-i>p/2)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(A, l, mid, n-1);
        }
    }
    if(p/2<n)
    {
        merge(A,0,p/2-1,n-1);
    }
} 

// Recursive merge sort

#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Merge(int A[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    int B[100];

    while(i<=mid && j<=h)
    {
        if(A[i]<A[j]){
        B[k++]=A[i++];
        }
        else{
            B[k++]=A[j++];
        }
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];
    for(i=l;i<=h;i++)
        A[i]=B[i];
}

void MergeSort(int A[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);

    }
}

// Count sort

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int findMax(int A[],int n)
{
    int max=INT32_MIN;
    int i;
    for(i=0;i<n;i++)
    {
        if(A[i]>max)max=A[i];
    }
    return max;
}
void CountSort(int A[],int n)
{
    int i,j,max,*C;

    max=findMax(A,n);
    C=(int *)malloc(sizeof(int)*(max+1));

    for(i=0;i<max+1;i++)
    {
        C[i]=0;
    }
    for(i=0;i<n;i++)
    {
        C[A[i]]++;
    }

    i=0;j=0;
    while(j<max+1)
    {
        if(C[j]>0)
        {
            A[i++]=j;
            C[j]--;
        }
        else j++;
    }
}

//Counting Sort

#include<stdio.h>
#include<string.h>

void countSort(int a[], int n){
	int arr[10];
	int max = a[0];
	for (int i = 1; i < n; i++) {
	    if (a[i] > max)
	    	max = a[i];
  	}
  	int count[10];
	memset(count,0,sizeof(count));

	for(int i=0; i<n; i++){
		++count[a[i]];
	}
	for(int j=1;j<=max;j++){
		count[j] = count[j] + count[j-1];
	}
	for (int i = n - 1; i >= 0; i--) {
	    arr[count[a[i]] - 1] = a[i];
	    count[a[i]]--;
  	}

  	for (int i = 0; i < n; i++) {
    	a[i] = arr[i];
  	}
}

int main(){
	int arr[] = {3,1,5,8,9};
	countSort(arr,5);
	for(int i=0;i<5;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
