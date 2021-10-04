// Find Duplicate Characters in a String.

import java.util.*;

public class DuplicateCharacters{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();
		x = x.toLowerCase();
		int a[] = new int[26];
		for(int i=0;i<x.length();i++){
			a[x.charAt(i)-97]++;
		}
		for(int i=0;i<26;i++){
			char c=(char)(97+i);
			if (a[i]>1)
				System.out.println("There are "+a[i]+" number of '"+c+"' in the input.");
		}
		sc.close();
	}
}