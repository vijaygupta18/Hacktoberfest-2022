import java.util.Scanner;

public class Palindrome_Number {

	public static void main(String[] args) {
		int n, temp,rev=0,rem;
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number : ");
		 n =s.nextInt();
		 temp=n;
		 while(temp!=0) 
		 {
			 // formula to calculate reverse of a number. 
			 rem = temp % 10; 
			 rev = rev * 10 + rem;
			 temp = temp / 10;
		 }
		 if(n==rev) // to check palindrome 
		 {
			 System.out.println("Number is Palindrome");
		 }
		 else
		 {
			 System.out.println("Number is not a Palindrome");
		 }
		 s.close();
	}

}
