// Check if two Arrays are equal.

import java.util.*;

public class ArrayEquality{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a1[] = {1,2,3,4,5};
		int a2[] = {1,2,3,4,6};
		System.out.println(Arrays.equals(a1, a2));
		sc.close();
	}
}
