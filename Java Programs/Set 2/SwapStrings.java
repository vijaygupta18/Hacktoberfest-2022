// Swap two strings with out using a third or temp variable - 29.

import java.util.*;

public	class SwapStrings {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();
		String y = sc.nextLine();
		int n = x.length();
		System.out.println(x + "\t" + y);
		x = x + y;
		y = x.substring(0, n);
		x = x.substring(n);
		System.out.println(x + "\t" + y);
		sc.close();
	}
}