// Reversing a String in Java.

import java.util.*;

public class StringReverse{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();
		StringBuilder sb = new StringBuilder();
		sb.append(x);
		sb.reverse();
		x = sb.toString();
		System.out.print(x);
		sc.close();
	}
}