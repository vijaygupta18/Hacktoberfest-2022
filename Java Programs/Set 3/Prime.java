// Find whether a number is a prime number or not - 12.

import java.util.*;

public class IntToString {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		String ans = "Prime";
		for (int i = 2; i <= Math.sqrt(x); i++){
			if (x % i == 0)
				ans = "Not Prime"; 
		}
		System.out.println(ans);

		sc.close();
	}
}