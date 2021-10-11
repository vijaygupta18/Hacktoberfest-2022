// Write a program to reverse each word of a given string with spaces being preserved - 13.

import java.util.*;

public class ReverseStringWithSpacesPreserved{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();
		String[] a = x.split(" ");
		String ans = "";
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < a.length; i++){
			sb.append(a[i]);
			sb.reverse();
			a[i] = sb.toString();
			sb.setLength(0);
			ans = ans + " " +a[i];
		}
		System.out.println(ans);
		sc.close();
	}
}
