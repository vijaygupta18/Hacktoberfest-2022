// Matrix Operations in java

import java.util.*;

public class MatrixOperations{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int a[][] = new int[n][m];
		int b[][] = new int[n][m];
		System.out.println("A");
		for(int i = 0;i < n; i++){
			for(int j = 0;j < m; j++){
				a[i][j] = sc.nextInt();
				System.out.print(a[i][j]+" ");
			}
			System.out.println();
		}
		System.out.println("B");
		for(int i = 0;i < n; i++){
			for(int j = 0;j < m; j++){
				b[i][j] = sc.nextInt();
				System.out.print(b[i][j]+" ");
			}
			System.out.println();
		}

		// Addition result
		System.out.println("A+B");
		for(int i = 0;i < n; i++){
			for(int j = 0;j < m; j++){
				System.out.print(a[i][j]+b[i][j]+" ");
			}
			System.out.println();
		}

		// Subraction a - b
		System.out.println("A-B");
		for(int i = 0;i < n; i++){
			for(int j = 0;j < m; j++){
				System.out.print(a[i][j]-b[i][j]+" ");
			}
			System.out.println();
		}

		// Transpose
		System.out.println("A-Transpose");
		for(int j = 0;j < m; j++){
			for(int i = 0;i < n; i++){
				System.out.print(a[i][j]+" ");
			}
			System.out.println();
		}

		System.out.println("B-Transpose");
		for(int j = 0;j < m; j++){
			for(int i = 0;i < n; i++){
				System.out.print(b[i][j]+" ");
			}
			System.out.println();
		}

		// Multiplication A * B results in an output matrix of N X N size.
		System.out.println("Multiplication");
		for(int j = 0;j < m; j++){
			for(int i = 0;i < n; i++){
				System.out.print(a[j][i]*b[i][j]+" ");
			}
			System.out.println();
		}

		sc.close();
	}
}
