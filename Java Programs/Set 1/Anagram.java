// Anagrams

import java.util.*;

public class Anagram{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.nextLine().toLowerCase();
		String b = sc.nextLine().toLowerCase();
		char a1[] = a.toCharArray();
		char b1[] = b.toCharArray();
		Arrays.sort(a1);
		Arrays.sort(b1);
		a = new String(a1);
		b = new String(b1);
		System.out.println(a.equals(b));
		sc.close();
	}
}