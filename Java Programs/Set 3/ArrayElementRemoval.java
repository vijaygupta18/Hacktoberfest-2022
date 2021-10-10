// Array Element Removal Program in Java - 10.

import java.util.*;

public class ArrayElementRemoval {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];

		for (int i = 0; i < n; i++)
			a[i]=sc.nextInt();

		int pos = sc.nextInt();
		for (int i = pos - 1; i < n - 1; i++)
			a[i] = a[i+1];

		for (int i = 0; i < n - 1; i++)
			System.out.println("a["+i+"] = "+a[i]);
	}
}
