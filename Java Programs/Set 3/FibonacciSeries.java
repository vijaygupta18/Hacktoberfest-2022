// Check whether a number can belong to the Fibonacci Series - 5.

import java.util.*;

public class FibonacciSeries {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		ArrayList<Integer> a = new ArrayList<Integer>();

		a.add(0); 
		a.add(1);
		int y = 0, count = 1;

		while (y < x){
			y = a.get(count - 1) + a.get(count);
			a.add(y);
			count++;
		}
		String ans = (a.contains(x)) ? "YES" : "NO";
		System.out.println(ans);

		sc.close();
	}
}