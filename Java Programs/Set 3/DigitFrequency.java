// Write a java program to find the frequency of all the digits - 23.

import java.util.*;

public class DigitFrequency {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long x = sc.nextLong();
		int[] a = new int[10];
		int p;

		while (x > 0){
			p = (int)(x % 10);
			a[p]++;
			x = x / 10;
		}

		for (int i = 0; i < 10; i++) {
			if(a[i] > 0)
				System.out.println(i + " : " + a[i]);
		}

		sc.close();
	}
}