// Write a program to reverse the word sequence in a sentence - 14.

import java.util.*;

public class ReverseWordsInSentece{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();
		String[] a = x.split(" ");
		String ans = "";

		for(int i = a.length - 1; i >= 0; i--)
			ans = ans + " " +a[i];
		System.out.println(ans);
		sc.close();
	}
}
