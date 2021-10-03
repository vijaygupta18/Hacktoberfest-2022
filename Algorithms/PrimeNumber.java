import java.util.Scanner;

class PrimeNumber {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println();
        		System.out.print("Enter the number: ");
		int n = sc.nextInt();
		
		System.out.println("Prime numbers between 1 to " + n + " are ");
		
		for(int i=2; i <= n; i++) {
			
			int count = 0;
			
			for(int j=2; j <= i/2; j++) {
				if(i % j == 0) {
				     count++;
				     break;
				}
			}
			
			if(count == 0) {
				System.out.print(i + "  ");
			}
			    
		}
		System.out.println();		
    		System.out.println("010_Sarthak_Maheshwari_IT-3");

	}

}
