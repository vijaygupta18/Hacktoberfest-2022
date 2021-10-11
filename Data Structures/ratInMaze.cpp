#include<iostream>
#define n 4
using namespace std;
bool isSafe(int** arr,int x,int y){
	if(x<n && y<n && x>=0 && y>=0 && arr[x][y]==1)
		return true;
	return false;
}

bool ratinMaze(int** arr,int x,int y, int** sol){
	if((x == n-1) && (y == n-1)){
	    sol[x][y]=1;
	    return true;
	}
	if(isSafe(arr,x,y)){
	    sol[x][y]=1;
	    if(ratinMaze(arr, x+1, y, sol))
	    return true;
	    if(ratinMaze(arr,x,y+1,sol))
	    return true;
	    sol[x][y]=0;
	    return false;
	}
	return false;
}
int main(){

	 int** arr=new int*[n];
	 int** sol=new int*[n];
	 for(int i=0;i<n;i++){
	 	arr[i]=new int[n];
	 	sol[i]=new int[n];
	 }
	 for(int i=0;i<n;i++){
	 	for(int j=0;j<n;j++)
	 		sol[i][j]=0;
	 }
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	}
	if(ratinMaze(arr,0,0,sol))
	{
		cout<<"Possible\n";
	}

	else
		cout<<"Not Possible\n";
	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<sol[i][j]<<" ";
			cout<<endl;
		}
	return 0;
}