// Write a java program to give the output in Roman Numerals in java - 14.

// https://capitalizemytitle.com/roman-numeral-generator/
import java.util.*;

public static RomanNumerals{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Only 4 Digit Numbers.");
		int n = sc.nextInt();
		String ans = "";
		int count = 1;
		while (n > 0){
			int x = n % 10;
			ans = Romanize(count, x) + ans;
			count = count + 1;
			n = n / 10;
		}
		System.out.println(ans);
		sc.close();
	}

	public static String Romanize(int i, int x){
		String ans = "";
		String[][] assigner = {{ "", "I", "II" ,"III", "IV", "V", "VI", "VII", "VIII", "IX"},
							   {"", "X", "XX" ,"XXX", "XL",	"L", "LX", "LXX", "LXXX", "XC"},
							   {"", "C", "CC" ,"CCC", "CD",	"D", "DC", "DCC", "DCCC", "CM"},
							   {"", "M", "M" ,"MMM", "I̅V̅",	"V̅", "V̅I̅", "V̅I̅I̅", "V̅I̅I̅I̅", "I̅X̅"}};
		ans = assigner[i-1][x];
		return ans;
	}
}