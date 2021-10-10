// Find duplicate elements in an Array.

import java.util.*;

public class ArrayDuplicates{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];
		for (int i = 0 ; i < n ;i++)
			a[i] = sc.nextInt();
		HashSet<Integer> hs = new HashSet<Integer>();
		for (int i = 0; i < n; i++){
			if(hs.contains(a[i])){
				System.out.println(a[i]+" is a duplicate");
			}
			else{
				hs.add(a[i]);	
			}
		}
		sc.close();
	}
}
