// Check whether a string is a rotation of another string - 3.

import java.util.*;

public class StringRotation{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();
		String y = sc.nextLine();

		if (x.length() != y.length()){
			System.out.println("Different String sizes.");
		}
		else{
			// KMP - Algorithm.
			x = x + x;
			int a = x.indexOf(y);
			if(a > 1)
				System.out.println(a+" Rotations to the left gives us the other string.");
			else
				System.out.println("Not a rotation");
		}
		sc.close();
	}
}
