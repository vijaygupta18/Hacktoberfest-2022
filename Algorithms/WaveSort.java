// A O(n) Java program to sort an input array in wave form
import java.util.*;

class Solution
{
    
   public static void swap(int arr[], int a, int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
 
  
   public static void sortInWave(int arr[], int n)
    {
    
        for (int i = 0; i < n; i+=2)
        {
           
            if (i>0 && arr[i-1] > arr[i] )
                swap(arr, i-1, i);
 
           
            if (i<n-1 && arr[i] < arr[i+1] )
                swap(arr, i, i + 1);
        }
    }
 
    public static void main(String args[])
    {
        int arr[] = {10, 90, 49, 2, 1, 5, 23};
        int n = arr.length;
         sortInWave(arr, n);
        for (int i : arr)
            System.out.print(i+" ");
    }
}