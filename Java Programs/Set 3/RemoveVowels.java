// Remove all the vowels in from a string in java - 16.

import java.util.*;

public class RemoveVowels {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();
		String ans = "";
		ArrayList a = new ArrayList(Arrays.asList('a', 'e', 'i', 'o', 'u', 'U', 'O', 'I', 'E', 'A'));
		for (int i = 0; i < x.length(); i++){
			if (!a.contains(x.charAt(i)))
				ans = ans + x.charAt(i);
		}
		System.out.println(ans);
		sc.close();
	}
}

