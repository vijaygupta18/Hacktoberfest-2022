// String Immutable Program - 17.

// String is immutable in java i.e to change a string we have reassign it explicitly.

import java.util.*;

public class StringImmutable{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();
		String y = sc.nextLine();
	
		System.out.println(x);
		System.out.println(x.concat(y));
		System.out.println(x);
		x = x.concat(y);
		System.out.println(x);
	
		sc.close();
	}
}