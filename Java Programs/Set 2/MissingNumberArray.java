// Find the missing number in java array - 16.

// Assuming that number are given from 1 till n with one number missing from the sequence.
// S=n(n+1)2 .

import java.util.*;

public class MissingNumberArray{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++){
			a[i] = sc.nextInt();
			sum = sum + a[i];
		}
		int ans = (((n+2) * (n+1)) / 2) - sum;
		System.out.print(ans);
		sc.close();
	}
}