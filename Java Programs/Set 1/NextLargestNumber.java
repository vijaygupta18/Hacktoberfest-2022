// Largest number less than a given number and without a digit.

import java.util.*;

public class NextLargestNumber{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int digit = sc.nextInt();
		
		String x = Integer.toString(num);
		int n = x.length();
		String y = "";
		String ans = 0;
		int max = (digit == 9) ? 8 : 9;
		for (int i = 0 ; i < n; i++)
			y=a+9;
		for (int i = n-1; i >= 0; i++){
			int a = Character.getNumeric(x.charAt(i));
			int b = Character.getNumeric(y.charAt(i));

		}

		System.out.println();
		sc.close();
	}
}

/*
Test Cases
145   4		139
444   4  	399
*/

// Solution 1

	// public static void main(String[] args) {
	// 	Scanner sc = new Scanner(System.in);
	// 	int n = sc.nextInt();
	// 	int digit = sc.nextInt();
		
	// 	while((Integer.toString(n)).contains(Integer.toString(digit))){
	// 		n = n - 1;
	// 	}

	// 	System.out.println();
	// 	sc.close();
	// }