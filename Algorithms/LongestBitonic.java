/*
Longest Bitonic Subarray Problem
The Longest Bitonic Subarray (LBS) problem is to find a subarray of a given sequence in which the 
subarray’s elements are first sorted in increasing order, then in decreasing order, and the subarray is as long as possible. 
Strictly ascending or descending subarrays are also accepted.
*/


/*
Longest bitonic subarray of the sequence { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 } is { 4, 5, 9, 10, 8, 5, 3 }
 
For sequences sorted in increasing or decreasing order, the output is the same as the input sequence, i.e.,
 
[1, 2, 3, 4, 5] ——> [1, 2, 3, 4, 5]
[5, 4, 3, 2, 1] ——> [5, 4, 3, 2, 1]
*/


class Main
{
    // Function to find the length of the longest bitonic subarray in an array
    public static void findBitonicSubarray(int[] A){
        if (A.length == 0) {
            return;
        }
 
        int[] I = new int[A.length];
        I[0] = 1;
        for (int i = 1; i < A.length; i++){
            I[i] = 1;
            if (A[i - 1] < A[i]) {
                I[i] = I[i - 1] + 1;
            }
        }
 
        // `D[i]` store the length of the longest decreasing subarray,
        // starting with `A[i]`
        int[] D = new int[A.length];
        D[A.length - 1] = 1;
        for (int i = A.length - 2; i >= 0; i--){
            D[i] = 1;
            if (A[i] > A[i + 1]) {
                D[i] = D[i + 1] + 1;
            }
        }
 
        // consider each element as a peak and calculate LBS
        int lbs_len = 1;
        int beg = 0, end = 0;
 
        for (int i = 0; i < A.length; i++){
            int len = I[i] + D[i] - 1;
            if (lbs_len < len){
                lbs_len = len;
                beg = i - I[i] + 1;
                end = i + D[i] - 1;
            }
        }
 
        // print the longest bitonic subarray
        System.out.println("The length of the longest bitonic subarray is " + lbs_len);
        System.out.printf("The longest bitonic subarray indices is [%d, %d]", beg, end);
    }
 
    public static void main(String[] args){
        int[] A = { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 };
 
        findBitonicSubarray(A);
    }
}