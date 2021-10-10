import java.util.*;

class Solution {
    public static int firstMissingPositive(int[] a) {
       long max=0;
        HashSet<Integer>s=new HashSet<>();
        for(int i=0;i<a.length;i++)
        {
            if(a[i]>=0)
                s.add(a[i]);
            if(a[i]>max)
                max=a[i];
        }
        for(int i=1;i<=max+1;i++)
        {
            if(!s.contains(i))
                return i;
        }
        return 0;
    }
    public static void main (String[] args) {
       int arr[] = {3,4,-1,1};
       int ans= firstMissingPositive(arr);
       System.out.println(ans);
    }
}