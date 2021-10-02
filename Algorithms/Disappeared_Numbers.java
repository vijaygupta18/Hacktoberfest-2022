package Codeforces;

import java.util.ArrayList;
import java.util.List;

public class Disappeared_Numbers {

	public static void main(String[] args) {
/*Given an array of n integers where arr[i] is in the range [1, n], 
* return an array of all the integers in the range [1, n] that do not appear in nums.*/		
		int []arr = {4,3,2,7,8,2,3,1};
		System.out.println(findDisappearedNumbers(arr));
	
	}
	public static List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> ans=new ArrayList<>();
        cyclicSort(nums);
       
         for(int i=0;i<nums.length;i++){
            if(i!=nums[i]-1){
                ans.add(i+1);
            }
        }
        
       return ans; 
    }
    public static void cyclicSort(int []arr){
        int i=0;
        while(i<arr.length){
            if(arr[i]==arr[arr[i]-1]){
                i++;
            }
           else if(i!=arr[i]-1){
               swap(arr,i,arr[i]-1);
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
