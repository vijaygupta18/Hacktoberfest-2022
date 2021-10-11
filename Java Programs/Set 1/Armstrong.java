// Check if a number is an Armstrong or Not.

import java.util.*;

public class Armstrong{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int temp = n;
        int rem, result = 0;
        while (n != 0){
            rem = n % 10;
            result += rem*rem*rem;
            n /= 10;
        }

        if(result == temp)
            System.out.println("Armstrong number.");
        else
            System.out.println("Not an Armstrong number.");

		sc.close();
    }
}