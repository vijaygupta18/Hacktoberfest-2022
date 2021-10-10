// Write a java program to find the percentage of upper, lower, digit and special characters - 15.

import java.util.*;

public class PercentageOfCharacters{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();
		int n = x.length();
		double u=0, l=0, d=0, s=0;
		for (int i = 0; i < n; i++){
			if(x.charAt(i) >= 65 && x.charAt(i) <= 90)
				u = u + 1;
			else if(x.charAt(i) >= 97 && x.charAt(i) <= 122)
				l = l + 1;
			else if(x.charAt(i) >= 48 && x.charAt(i) <= 57)
				d = d + 1;
			else
				s = s + 1;
		}
		System.out.println("Size: " + n);
		System.out.println("Upper: " + u*100/n);
		System.out.println("Lower: " + l*100/n);
		System.out.println("Digit: " + d*100/n);
		System.out.println("Special Character: " + s*100/n);
		sc.close();
	}
}