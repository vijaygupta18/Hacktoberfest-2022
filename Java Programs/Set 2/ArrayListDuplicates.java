// Program to delete the duplicates from an ArrayList - 1.

import java.util.*;

public class ArrayListDuplicates {
	public static void main(String[] args) {
		ArrayList<Integer> a = new ArrayList<Integer>();
		Set<Integer> s = new HashSet<Integer>();
		
		a.add(33);
    	a.add(15);
    	a.add(20);
    	a.add(34);
    	a.add(8);
    	a.add(12);

        a.add(33);
    	a.add(15);
    	a.add(20);
    	a.add(34);
    	a.add(8);
    	a.add(12);
    	
        System.out.println("ArrayList Before: "+a);
    	s.addAll(a);
		a.clear();
		a.addAll(s);
		System.out.println("ArrayList After: "+a);


		ArrayList<String> a1 = new ArrayList<String>();
		Set<String> s1 = new HashSet<String>();
		
		a1.add("Volvo");
		a1.add("BMW");
    	a1.add("Ford");
    	a1.add("Mazda");
    	a1.add("Volvo");
		a1.add("BMW");
    	a1.add("Ford");
    	a1.add("Mazda");
        
        System.out.println("ArrayList Before: "+a1);
    	s1.addAll(a1);
		a1.clear();
		a1.addAll(s1);
		System.out.println("ArrayList After: "+a1);
	}
}