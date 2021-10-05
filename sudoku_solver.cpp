#include <bits/stdc++.h>

using namespace std;

#define n 9

bool isValid(int mat[][n],int i,int j,int no){
	for (int k= 0; k < n; ++k)
	{
		if(mat[i][k]==no || mat[k][j]==no)	return false;

	}
	int sx=(i/3)*3;
	int sy=(j/3)*3;
	for( int x=sx;x<sx+3;x++){
		for (int y = sy; y < sy+3; ++y)
		{
			if(mat[x][y]==no)	return false;

		}
	}


	return true;
}


bool solve_sudoku(int mat[n][n],int i,int j ){
	if(i==n){
		for (int x = 0;x< n; ++x)
    	{
    		for (int y = 0; y < n; ++y)
    		{
    			cout<<mat[x][y]<<" ";
    		}
    		cout<<endl;
    	}
    	return true;	
    }

	if(j==n){
		return solve_sudoku(mat,i+1,0);
	}
	if(mat[i][j]!=0)	return solve_sudoku(mat,i,j+1);

	for(int no=1;no<=9;no++){

	if(isValid(mat,i,j,no)){
		mat[i][j]=no;
		if(solve_sudoku(mat,i,j+1))	return true;

	}
	}
	mat[i][j]=0;
	return false;

}
int main(){
	int mat[n][n]={ {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
         {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
         {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
         {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
         {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
         {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
         {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
         {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };

    if(!solve_sudoku(mat,0,0)){
    	cout<<"No solution exists";
    }
    
    
}