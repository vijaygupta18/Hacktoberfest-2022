// Reverse an Array in java - 28.

import java.util.*;

public class ArrayReverse {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = sc.nextInt();
		int i = 0;
		n = n - 1;
		while (i < n){
			int x = a[i];
			a[i++] = a[n];
			a[n--] = x;
		}	
		for (i = 0; i < a.length; i++)
			System.out.print(a[i] + " ");
		sc.close();
	}
}