// Implement Selection Sort in java - 12.

/*
	Selects the minimum element and puts it at the end of the sorted list.
	At any point we have two sub arrays which are the sorted and unsorted ones.
*/

import java.util.*;

public class SelectionSort{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i]=sc.nextInt();
		SelectionSortArray(a, n);
		for (int i = 0; i < n; i++)
			System.out.print(a[i] + " ");
	}

	public static void SelectionSortArray(int a[], int n){
		for (int i = 0; i < n; i++){
			int min_index = 0;
			for (int j = i + 1; j < n-1; j++){
				if (a[j] < a[i]){
					min_index = j;
				}
			}
			int temp = a[i];
			a[i] = a[min_index];
			a[min_index] = temp;
		}
	}
}