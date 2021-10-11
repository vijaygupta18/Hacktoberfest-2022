// Trigonometric Functions in java - 6.

import java.util.*;

public class TrigonometricFunctions{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double input = sc.nextDouble();
		input = Math.toRadians(input);
		System.out.println("Sine: " + Math.sin(input));
		System.out.println("Coine: " + Math.cos(input));
		System.out.println("Tangent: " + Math.tan(input));
		System.out.println("Cosecant: " + 1/Math.sin(input));
		System.out.println("Secant: " + 1/Math.cos(input));
		System.out.println("Co-Tangent: " + 1/Math.tan(input));
		sc.close();
	}
}