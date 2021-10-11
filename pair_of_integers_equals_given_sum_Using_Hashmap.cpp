#include<iostream>
#include<unordered_map>
using namespace std;

int getPairsCount(int arr[], int n, int k) {
       unordered_map<int,int>map;
      int count=0;
      for(int i=0;i<n;i++){
         map[arr[i]]++;
      }
      for(int i=0;i<n;i++){
       count=count+map[k-arr[i]];
       if(k-arr[i]==arr[i]){
           count--;
       }
      }
       return count/2;

   

int main(){
int a[]={1, 1, 1, 1};
int k=2,sum=0,start=0,end=0;
int n=sizeof(a)/sizeof(a[0]);
cout<<getPairsCount(a, n,k)<<endl;
    return 0;
}
