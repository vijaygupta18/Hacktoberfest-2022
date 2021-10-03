import java.io.*;
 
class Main {
 
   public static int maxSubArraySum(int a[], int size)
    {
        int current=0;
        int maxSum=0;
 
    for (int i = 1; i < size; i++)
    {
        current+=a[i];
        maxSum=Math.max(current,maxSum);
        if(current<0)
        current=0;
    }
    return maxSum;
    }
 
    public static void main(String[] args)
    {
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = a.length;  
    int ans = maxSubArraySum(a, n);
    System.out.println("Maximum contiguous sum is "
                       +ans);
    }
}