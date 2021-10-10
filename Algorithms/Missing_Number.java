package Codeforces;

public class Missing_Number {

	public static void main(String[] args) {
/*From an array containing n distinct numbers in the range [0, n],
 return the only number in the range that is missing from the array.*/
		int[] nums = {3,0,1};
	    System.out.println(missingNumber(nums)); 
	}
	 public static int missingNumber(int[] nums) {
	       cyclicSort(nums);
	        for(int i=0;i<nums.length;i++){
	            if(nums[i]!=i){
	                return i;
	            }
	        }
	        return nums.length;
	    }
	 
	  public static void cyclicSort(int []arr){
	        int i=0;
	        while(i<arr.length){
	            if(arr[i]==arr.length){
	                i++;
	            }else if(i!=arr[i]){
	                swap(arr,i,arr[i]);
	            }else{
	                i++;
	            }
	            
	        }
	        
	    } 
	    
	  public static void swap(int []arr,int first,int sec){
	        int temp=arr[first];
	        arr[first]=arr[sec];
	        arr[sec]=temp;
	    }

}
