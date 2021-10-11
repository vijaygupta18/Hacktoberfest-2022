// Convert Decimal to Binary, Octal and Hexadecimal formats - 9.

import java.util.*;

public DecimalConversions{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		System.out.println("Binary: " + Integer.toBinaryString(x));
		System.out.println("Octal: " + Integer.toOctalString(x));
		System.out.println("Hexadecimal: " + Integer.toHexString(x));
		sc.close();
	}
}