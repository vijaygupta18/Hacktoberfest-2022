package Algorithms;

public class Binary_Search_In_2D_Matrix_02 {

	public static void main(String[] args) {
//	It is an algorithm that searches for a value in an m x n matrix in a strictly sorted matrix. 
//	This matrix has the following properties:
//  Integers in each row are sorted from left to right.
//  The first integer of each row is greater than the last integer of the previous row.
		
		
	int [][] matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
	System.out.println(searchMatrix(matrix, 10));

	}
	public static boolean searchMatrix(int[][] arr, int target) {
        int r=arr.length;
        int c=arr[0].length;
        
       
        
        if(r==1 && c>1){
           return BinarySearch(arr[0],0,c-1,target); 
        }
        
        int cMid=(c-1)/2;
        int rStart=0;
        int rEnd=r-1;
        while(rStart<(rEnd-1)){
            int mid=rStart+(rEnd-rStart)/2;
            if(arr[mid][cMid]==target){
                return true;
            }else if(arr[mid][cMid]>target){
                rEnd=mid;
            }else{
                rStart=mid;
            }
        }
        
        if(arr[rStart][cMid]==target){
            return true;
        }else if(arr[rEnd][cMid]==target){
            return true;
        }
        if(arr[rStart][cMid]>target){
            return BinarySearch(arr[rStart],0,cMid-1,target);
        }else if(arr[rStart][cMid]<target && arr[rStart][c-1]>=target){
            return  BinarySearch(arr[rStart],cMid+1,c-1,target);
        }else if(arr[rEnd][cMid]>target){
            return  BinarySearch(arr[rEnd],0,cMid-1,target);
        }else{
             return  BinarySearch(arr[rEnd],cMid+1,c-1,target);
        }        
    }
	
    static boolean BinarySearch(int[]arr,int cStart,int cEnd,int target){
        int s=cStart;
        int e=cEnd;
        while(s<e){
            int mid=s+(e-s)/2;
            if(arr[mid]==target){
                return true;
            }else if(arr[mid]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        if(s==e){
            return arr[s]==target;
        }
        return false;
    }

}
