// Write a java program to find all the leaders in an integer array. 
// An element is said to be a leader if all the elements on it's right side 
// are smaller than it. Rightmost element is always a leader. - 10.

import java.util.*;

public class LeaderInArray{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for(int i = 0; i < n; i++)
			a[i]=sc.nextInt();

		int max = a[n-1];
		System.out.print(max + "\t");
		for(int i = n-2; i > 0; i--){
			if (a[i] > max){
				max = a[i];
				System.out.print(max + "\t");
			}
		}
		sc.close();
	}
}
