package Algorithms;

public class Binary_Search_In_2D_Matrix {

	public static void main(String[] args) {
//		Search in an 2D matrix in which the matrix is column and row wise sorted.It returns true if target element is present and false if not present
		int [][]matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
		System.out.println(searchMatrix(matrix, 5));
	}
	
    public static boolean searchMatrix(int[][] arr, int target) {
        int r=0;
        int c=arr[0].length-1;
        
        while(r<arr.length && c>=0){
            if(arr[r][c]==target){
                return true;
            }else if(arr[r][c]>target){
                c--;
            }else{
                r++;
            }
           
        }
        
         return false;
        
        
        
        
    }
    public static boolean searchMatrix2(int[][] arr, int target){
      int r=arr.length;
        int c=arr[0].length;
        
        
        int rStart=0;
        int rEnd=r-1;
        int cStart=0;
        int cEnd=c-1;
        while(rStart<=rEnd &&cStart<=cEnd){
            if(arr[rStart][cEnd]==target || arr[rEnd][cStart]==target ){
                return true;
            }
            if(arr[rStart][cEnd]<target){
                rStart++;
            }else{
                cEnd--;
            }
            if(arr[rEnd][cStart]>target){
                rEnd--;
            }else{
               cStart++; 
            }
        }
        return false;
          
    }
}

