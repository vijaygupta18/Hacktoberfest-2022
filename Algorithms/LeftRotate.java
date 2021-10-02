import java.util.Arrays;
import java.util.Scanner;

class LfRotate{
    void leftRotate(int arr[], int d)
    {
        for (int i = 0; i < d; i++)
            shift(arr);
    }
 
    void shift(int arr[])
    {
        int i, b;
        b = arr[0];
        for (i = 0; i < arr.length - 1; i++)
            arr[i] = arr[i + 1];
        arr[arr.length-1] =b;
    }
}
public class LeftRotate {
    public static void main(String[] args)throws Exception {
     try {
     Scanner sc = new Scanner(System.in);
     System.out.print("Array Size : ");
     int size=sc.nextInt();
     int []arr = new int [size];
     System.out.println("\nEnter Array Elements : ");
     for (int i = 0; i < arr.length; i++) {
     arr[i] = sc.nextInt();   
     }
     
     System.out.print("Enter position of D place : ");
     int D=sc.nextInt();
     LfRotate obj = new LfRotate();
     System.out.println("\nBefore Rotate Array is : "+Arrays.toString(arr));
     obj.leftRotate(arr, D);
     System.out.println("\nAfter  Rotate Array is : "+Arrays.toString(arr));
     sc.close();   
     } catch (Exception e) {
         System.out.println(e);
     }   
    }
}
