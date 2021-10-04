// An example of Array.deepToString() method - 18.

// .toString() works only for the 1-D Arrays,
// .deepToString() also works for the 2-D Arrays as well.

import java.util.*;

public class ArrayDeepToString {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String[] strs = new String[] {"Pranav", "Suryadevara"};
        System.out.println(Arrays.toString(strs));

		int[][] mat = new int[2][2];
        mat[0][0] = 99;
        mat[0][1] = 151;
        mat[1][0] = 30;
        mat[1][1] = 50;
        System.out.println(Arrays.toString(mat));
        System.out.println(Arrays.deepToString(mat));
		sc.close();
	}
}