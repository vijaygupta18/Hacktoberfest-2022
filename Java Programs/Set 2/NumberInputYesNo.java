// Check whether a user has given a number as an input or not - 5

public class NumberInputYesNo{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		try{
			double number = sc.nextDouble();
			System.out.println("Yes the input is a number: " + number);
		}
		catch (Exception e){
			e.printStackTrace();
			System.out.print("Not a number");
		}	
		finally{	
			sc.close();
		}
	}
}
