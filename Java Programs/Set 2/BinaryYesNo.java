// Check whether a given number is a binary number or not - 2.

import java.util.*;

public class BinaryYesNo{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String a = sc.nextLine();
		boolean flag = true;
		for (int i = 0; i < a.length(); i++){
			if (a.charAt(i) != '0' && a.charAt(i) != '1'){
				flag = false;
				break;
			}
		}
		a = (flag == false) ? "NO" : "YES";
		System.out.println(a);
		sc.close(); 
	}
}