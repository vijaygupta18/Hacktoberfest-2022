// Write a program to reverse each word of a given string - 7.

import java.util.*;

public class ReverseString{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();
		String[] a = x.split(" ");
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < a.length; i++){
			System.out.print(a[i]+"\t");
			sb.append(a[i]);
			sb.reverse();
			a[i] = sb.toString();
			sb.setLength(0);
			System.out.println(a[i]);
		}
		sc.close();
	}
}
