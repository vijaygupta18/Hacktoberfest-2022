//BINARY SEARCH
//Time complexity=> O(logn base2)
//Take a sorted array and then try to find the no. from the mid, not from starting
//eg: take bundle of sheets and you need to find your roll no., so you'll pick randomly 1 sheet from the middle of bundle and accordingly divide the first half, second half of sheets to find your sheet.

#include<iostream>
using namespace std;

int binarysearch(int array[], int n,int key){
	int s=0; //starting point be s
	int e=n; //ending point be e
	while(s<=e){
		int mid=(s+e)/2; //index of mid point 
				
		if(array[mid]==key){
			return mid;
		}	
		else if(array[mid]>key){ //key will be present in the first half
		e=mid-1; //to reach in first half, we did ending point=mid-1
		}
		else{
			s=mid+1; //we're in second half so starting point will be mid point+1
				}
		}
		return -1;
		
}

int main(){
	int n;
	cout<<"enter the size of array: ";
	cin>>n;
	int array[n];
	cout<<"enter array: ";
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	int key;
	cout<<"enter the no. you want to find: ";
	cin>>key;
 cout<<"desired no. is at: ";
 cout<<binarysearch(array,n,key);
 
 return 0;
}
