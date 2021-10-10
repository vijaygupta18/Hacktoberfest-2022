// Generate Random Numbers in java - 21.

import java.util.*;

public class RandomNumbers{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Max and Min Values.");
		int x = sc.nextInt();
		int y = sc.nextInt();
		// e.g. 1-10 => random*(10-1+1) + 1. 
		int ans = (int)(Math.random()*(x-y+1)+y);  
		System.out.println(ans);
		sc.close();
	}
}
