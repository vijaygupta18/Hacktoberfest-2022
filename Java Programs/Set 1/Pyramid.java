// Pyramid of Numbers.

import java.util.*;

public class Pyrmaid{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x = 1;
		for (int i = 1; i <= n; i++){
			Set<Integer> hs = new HashSet<Integer>();
			int a = -1 * (i-1);
			while (a < i){
				hs.add(n-a);
				a = a + 2;
			}
			for (int j = 1; j < 2*n; j++){
				if (hs.contains(j)){
					System.out.print(x);
					x = x + 1;
				}
				else{
					System.out.print(" ");
				}
			}
			System.out.println();
		}
		sc.close();
	}
}
