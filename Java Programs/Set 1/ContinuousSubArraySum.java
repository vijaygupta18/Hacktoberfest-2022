import java.util.*;

public class ContinuousSubArraySum{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int sum = sc.nextInt();
		int n = sc.nextInt();
		int a[] = new int[n];
		for (int i = 0;i < n; i++)
			a[i] = sc.nextInt();
		boolean flag = false;
		int i=0, j=0;
		// Corener Cases.
		if (sum == a[i])
		    System.out.print("The ContinuousSubArray for the given sum is, the first element itself " + a[0]);
		else if (sum == a[n-1])
		    System.out.print("The ContinuousSubArray for the given sum is, the last element itself " + a[n-1]);
		else {
		for (i = 0; i < n - 1; i++){
			int x = a[i];
			for (j = i + 1; j < n; j++){
				if (x > sum){
					break;
				}		
				else{
					x = x + a[j];
				}	
				if (x == sum){
					flag = true;
					System.out.println("Final: "+x+"  "+i+"  "+j);
					break;
				}
				System.out.println(x+"  "+i+"  "+j);
			}
			if (flag){
				break;
			}
		}
		System.out.print("The ContinuousSubArray for the given sum is, ");
		for (int k = i; k <= j; k++){
			System.out.print(a[k]+" ");
		}
		}
		sc.close();
		
	}
}
