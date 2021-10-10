// Find the Saddle Point of a Matrix - 19.

import java.util.*;

public class SaddlePoint {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x[][] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
		for (int i = 0; i < x.length; i++){
			int min = Integer.MAX_VALUE;
			int pos = 0;
			for (int j = 0; j < x[i].length; j++){
				if (min > x[i][j]){
					pos = j;
					min = x[i][j];
				}
			}
			int max = Integer.MIN_VALUE;
			for (int k = 0; k < x.length; k++)
				max = (max < x[k][pos]) ? x[k][pos] : max;
			// System.out.println(i + " " + max + " " + min);
			if (max == min)
				System.out.println("SaddlePoint: " + max);
		}

		sc.close();		
	}
}

