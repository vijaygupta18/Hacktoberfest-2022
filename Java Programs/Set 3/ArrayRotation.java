// Array Rotation Program in Java - 11.

import java.util.*;

public class ArrayRotation {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];

		for (int i = 0; i < n; i++)
			a[i]=sc.nextInt();

		int times = sc.nextInt();
		times = times % n;
		int temp = 0;
		while (times-- > 0){
			temp = a[0];
			for (int i = 0; i < n - 1; i++){
				a[i] = a[i + 1];
			}
			a[n-1] = temp;
		}

		for (int i = 0; i < n; i++)
			System.out.println("a["+i+"] = "+ a[i]);
	}
}



