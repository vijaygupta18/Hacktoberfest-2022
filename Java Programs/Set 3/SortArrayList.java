// Write a Java Program to Sort an ArrayList - 3.

import java.util.*;

public class SortArrayList {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		ArrayList<Integer> a = new ArrayList<Integer>();
		a.add(1);
		a.add(12);
		a.add(8);
		a.add(5);
		a.add(3);
		a.add(6);
		a.add(2);

		Iterator itr=a.iterator();
		while(itr.hasNext()){
	        int obj = (int)itr.next();
	        System.out.print(obj + " ");
	    }
        
        System.out.print("\nAfter Sorting: ");
		Collections.sort(a);	 
		itr=a.iterator();
		while(itr.hasNext()){
	        int obj = (int)itr.next();
	        System.out.print(obj + " ");
	    }   
	}
}
