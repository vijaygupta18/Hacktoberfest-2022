package Algorithms;
import java.util.Scanner;
public class Lecture8_3_3_InsertionSort {

	public static void main(String[] args) {
// for InsertionSort,insert an element from unsorted array 
//	to its correct position in sorted array	
	
		Scanner sc  = new Scanner (System.in);
		
		int n=sc.nextInt();
		
		int []arr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=sc.nextInt();	
		}
		for(int i=1;i<n;i++) {
			int currentNumber=arr[i];
			int j=i-1;
			while(arr[j]>currentNumber && j>=0) {
				arr[j+1]=arr[j];
				j--;
				
			}
			arr[j+1]=currentNumber;
		}
		
		for(int i=0;i<n;i++) {
			System.out.println(arr[i]);
		}
		
		sc.close();
	}

}
