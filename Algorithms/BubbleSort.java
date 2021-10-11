package Algorithms;
import java.util.Scanner;
public class Lecture8_3_2_BubbleSort {

	public static void main(String[] args) {
//      for bubble sort,repeatedly swap 2 adjacent elements if they are in wrong order 
		Scanner sc  = new Scanner (System.in);
		
		int n=sc.nextInt();
		
		int []arr=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=sc.nextInt();	
		}
		
		int counter=1;
		while(counter<n) {
			for(int i=0;i<n-counter;i++) {
				if(arr[i]>arr[i+1]) {
					int temp=arr[i];
					arr[i]=arr[i+1];
					arr[i+1]=temp;
					
				}
			}
			counter+=1;
		}
		
		for(int i=0;i<n;i++) {
			System.out.println(arr[i]);
		}
		
		sc.close();
	}

}
