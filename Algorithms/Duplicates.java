package Codeforces;

import java.util.ArrayList;
import java.util.List;

public class Duplicates {

	public static void main(String[] args) {
/* Given an integer array nums of length n where all the integers of nums are in the 
 * range [1, n] and each integer appears once or twice, return an array of all the integers that 
 * appears twice.*/		
		int []nums = {4,3,2,7,8,2,3,1};
		System.out.println(findDuplicates(nums));
	}
	 public static List<Integer> findDuplicates(int[] nums) {
	        cyclicSort(nums);
	        List<Integer> ans=new ArrayList<>();
	        for(int i=0;i<nums.length;i++){
	            if(i!=nums[i]-1){
	                ans.add(nums[i]);
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
