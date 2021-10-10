// Separate Zeroes and Non-Zeores in an Array - 8.

import java.util.*;

public class SeparateZeroesArray{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] a = {1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9};
		Arrays.sort(a);
		
		for (int i = 0; i <  a.length; i++){
            System.out.print(a[i]+" ");
		}
    
        System.out.println();
    	
		int[] b = {1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9};
		int n = b.length - 1;
		int i = 0;
		while (i<n){
			while (b[n] == 0){
					n = n-1;
			}
			if (b[i] == 0){
				int x = b[n];
				b[n] = 0;
				b[i] = x;
			}
			i = i + 1;
		}

		for (i = 0; i <  b.length; i++){
            System.out.print(b[i]+" ");
		}

		System.out.println();

		int[] c = {1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9};
		// O(n)
		int x = 0;
		for (i = 0; i <  c.length; i++){
			if (c[i] != 0){
				c[x] = c[i];
				x = x + 1;
			}
		}		
		while(x < c.length){
			c[x] = 0;
			 x = x + 1;
		}

		for (i = 0; i <  c.length; i++){
            System.out.print(c[i]+" ");
		}


		sc.close();
	}
}
