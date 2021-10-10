// Write a Java Program to print Floyds Triangle - 6.

import java.util.*;

public class FloydsTrinagle {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		int k = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				System.out.print(k + " ");
				k = k + 1;
			}
			System.out.println();
		}
	}
}