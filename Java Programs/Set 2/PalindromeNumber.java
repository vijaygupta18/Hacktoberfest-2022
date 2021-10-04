// Take a number input and reverse it and add it to itself, 
// repeat the procedure until it is a palindrome - 11.

import java.util.*;

public class PalindromeNumber{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.nextLine();
		StringBuilder sb = new StringBuilder();
		sb.append(a).reverse();
		String b = sb.toString();
		sb.setLength(0);
		boolean flag = true;
		int count = 0;
		while (flag){
			int x = Integer.parseInt(a);
			int y = Integer.parseInt(b);
			x = x + y;
			a = Integer.toString(x);
			sb.append(a).reverse();
			b = sb.toString();
			sb.setLength(0);
			
			if (a.equals(b)){
				flag = false;
			}

			count = count + 1;
		}
		System.out.print(count);
		sc.close();
	}
}