/*Open addressing:
1) Linear Probing
2) Quadratic Probing
3) Double Hashing
*/

#include<iostream>
using namespace std;

//Linear probing by array
struct MyHash
{
	int *arr;
	int size,cap;
	MyHash(int cap)
	{
		arr=new int[cap]; //dynamic creating Hash table array
		this->cap=cap;
		size=0;
		for(int i=0;i<cap;++i) //filling -1 in every index
			arr[i]=-1;
	}
	
	int hash(int key) //hash function
	{
		return key%cap;
	}
	
	bool searchKey(int key)
	{
		if(size==0) return false;
		
		int h=hash(key);
		int i=h;
		while(arr[i]!=-1) //search till an empty index is found
		{
			if(arr[i]==key) return true; //found
			i=(i+1)%cap; //increasing index
			if(i==h) return false; //if traversed all indexes
		}
		return false;
	}
	
	bool insertKey(int key)
	{
		if(size==cap) return false;
		
		int i=hash(key);
		
		while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key) //search a index till a empty or deleted or duplicate key is found
		{
			i=(i+1)%cap;
		}
		
		if(arr[i]==key) return false; //if key already present
			
		arr[i]=key;
		++size;
		return true;		
	}
	
	bool deleteKey(int key)
	{
		if(size==0) return false;
		int h=hash(key);
		int i=h;
		while(arr[i]!=-1) //searching till an empty index is found
		{
			if(arr[i]==key) //if found
			{
				arr[i]=-2; //mark as DELETED
				--size;
				return true;
			}
			i=(i+1)%cap;
			if(i==h) return false;
		}
		return false;
	}
	
	void display()
	{
		cout<<"\nPrinting Hash Table:- \n";
		for(int i=0;i<cap;++i)
			cout<<arr[i]<<" ";
		cout<<"\n";
	}
};


int main()
{
	MyHash h(7);
	h.insertKey(50);
	h.insertKey(51);
	h.insertKey(49);
	h.insertKey(16);
	h.insertKey(56);
	h.insertKey(15);
	h.insertKey(15);
    //cout<<h.insertKey(60);
	h.display();
	h.deleteKey(50);
	h.deleteKey(15);
	h.insertKey(10);
	h.display();
	
}