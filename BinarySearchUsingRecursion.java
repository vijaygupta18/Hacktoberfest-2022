import java.util.*;

public class BinarySearchUsingRecursion {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
          arr[i] = in.nextInt();
        }
        int target = in.nextInt();
        System.out.println(bSearch(arr, target, 0, arr.length - 1));
    }

    static int bSearch(int[] arr, int target, int s, int e) {
        if (s > e)
            return -1;
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
            return mid;
        if (target < arr[mid])
            return bSearch(arr, target, s, mid - 1);
        return bSearch(arr, target, mid + 1, e);
    }
}
