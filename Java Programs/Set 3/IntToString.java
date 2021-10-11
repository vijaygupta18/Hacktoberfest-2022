// String to Integer and Integer to String Conversions in Java - 9.

import java.util.*;

public class IntToString {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();
		int a = Integer.parseInt(x);
		System.out.println(((Object)a).getClass().getSimpleName());

		String y = Integer.toString(x);
		System.out.println(y.getClass().getName());		


		sc.close();
	}
}