#include<iostream>
using namespace std;
void Reverse_Array(int *arr,int n)
{
    int start=0;
    int end=n-1;
    while(end>start)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    //return arr;
}
 
void print(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int size;
    cin>>size;
    int *arr=new int[size];
    for(int i=0;i<size;i++)
    {
      cin>>arr[i];
    }
     Reverse_Array(arr,size);
     print(arr,size);
     return 0;
}