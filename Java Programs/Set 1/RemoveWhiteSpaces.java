// Removing White Spaces from a String

import java.util.*;

public class RemoveWhiteSpaces{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();
		System.out.println("Before:"+x+":");
		System.out.println("After:"+x.strip()+":");

		sc.close();
	}
}
