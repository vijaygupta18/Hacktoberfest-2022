package Algorithms;
import java.util.Scanner;
public class Lecture8_3_1_SelectionSort {

	public static void main(String[] args) {
//		Sorting is used to arrange the array in ordered(ascending/descending)manner

//		for SelectionSort,find the minimum element in unsorted array 
//		and swap it with the element  at beginning
		Scanner sc  = new Scanner (System.in);
		
		int n=sc.nextInt();
		
		int []arr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=sc.nextInt();	
		}
		
		for(int i=0;i<n-1;i++) {
			for(int j=i+1;j<n;j++) {
				if(arr[i]>arr[j]) {
					int temp=arr[j];
					arr[j]=arr[i];
					arr[i]=temp;
				}
			}
		}
		for(int i=0;i<n;i++) {
		System.out.println(arr[i]);
	}
		sc.close(); 
}}
