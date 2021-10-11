/* 
	Maximum Sum Circular Subarray
		Given a circular Integer array, find a subarry with the largest sum in it.
*/

/*

TestCases:

Input:  {2, 1, -5, 4, -3, 1, -3, 4, -1}
Output: Subarray with the largest sum is {4, -1, 2, 1} with sum 6.
  
Input:  {-3, 1, -3, 4, -1, 2, 1, -5, 4}
Output: Subarray with the largest sum is {4, -1, 2, 1} with sum 6.
*/	


import java.util.Arrays;
 
class Main {
    // Function to find contiguous subarray with the largest sum
    // in a given set of integers
    public static int kadane(int[] A){
        // stores the sum of maximum subarray found so far
        int max_so_far = 0;
 
        // stores the maximum sum of subarray ending at the current position
        int max_ending_here = 0;
 
        // traverse the given array
        for (int value: A){
            // update the maximum sum of subarray "ending" at index `i` (by adding the
            // current element to maximum sum ending at previous index `i-1`)
            max_ending_here = max_ending_here + value;
 
            // if the maximum sum is negative, set it to 0 (which represents
            // an empty subarray)
            max_ending_here = Integer.max(max_ending_here, 0);
 
            // update result if the current subarray sum is found to be greater
            max_so_far = Integer.max(max_so_far, max_ending_here);
        }
 
        return max_so_far;
    }
 
    // Function to find the maximum sum circular subarray in a given array
    public static int runCircularKadane(int[] A){
        // empty array has sum of 0
        if (A.length == 0) {
            return 0;
        }
 
        // find the maximum element present in a given array
        int max = Arrays.stream(A).max().getAsInt();
 
        // if the array contains all negative values, return the maximum element
        if (max < 0) {
            return max;
        }
 
        // negate all the array elements
        Arrays.setAll(A, i -> -A[i]);
 
        // run Kadane’s algorithm on the modified array
        int neg_max_sum = kadane(A);
 
        // restore the array
        Arrays.setAll(A, i -> -A[i]);
 
        /* Return the maximum of the following:
            1. Sum returned by Kadane’s algorithm on the original array.
            2. Sum returned by Kadane’s algorithm on the modified array +
               the sum of all the array elements.
        */
 
        return Integer.max(kadane(A), Arrays.stream(A).sum() + neg_max_sum);
    }
 
    public static void main(String[] args){
        int[] A = { 2, 1, -5, 4, -3, 1, -3, 4, -1 };
 
        System.out.println("The sum of the subarray with the largest sum is " +
                runCircularKadane(A));
    }
}








