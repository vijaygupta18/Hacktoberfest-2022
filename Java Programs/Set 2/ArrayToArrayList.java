// Write a java program to convert an Array to ArrayList and ArrayList to Array - 25.

import java.util.*;

class ArrayToArrayList {
	public static void main(String[] args) {
		// This works for strings only but for numbers add the number as a list directly or use a for loop
		// List<Integer> a2 = new ArrayList<Integer>(Arrays.asList(1,2,3,4,5));


		String[] a = {"anna", "manna", "panna"};

		// This doesn't let the extra elements to be added, 
		// only useful to create an ArrayList of fixed size.
		List<String> a1 = Arrays.asList(a);
		System.out.println("1. " + a1);
		// This allows us to add aditional elements
		List<String> a2 = new ArrayList<String>(Arrays.asList(a));
		a2.add("kanna");
		System.out.println("2. " + a2);

		List<String> a3 = new ArrayList<String>();
		// using the Collection.addAll(collection, array) method.
		Collections.addAll(a3, a);
		System.out.println("3. " + a3);

		// Manually adding elements is one more.

	}	
}

class ArrayListToArray {
	public static void main(String[] args) {
		List<Integer> al = new ArrayList<Integer>();
        al.add(10);
        al.add(20);
        al.add(30);
        al.add(40);
  		
  		// toArray() method returns an array of type Object i.e an Array of Objects.
        Object[] objects = al.toArray();
		System.out.println("1.");
        for(Object x: objects)
			System.out.print(x + " ");
		// Integer[] objects = al.toArray(); =>=>=>throws error
		
		System.out.println("\n2.");
		Integer[] a = new Integer[al.size()];
        a = al.toArray(a);
        for (Integer x : a)
            System.out.print(x + " ");

        System.out.println("\n3.");
        // Using Stream API.
        int[] arr = al.stream().mapToInt(y -> y).toArray();
        for (int x : arr)
            System.out.print(x + " ");

        // https://www.geeksforgeeks.org/stream-maptoint-java-examples/
        System.out.println("\n4.");
        List<String> list = Arrays.asList("3", "6", "8", "14", "15");
        list.stream().mapToInt(num -> Integer.parseInt(num))
                     .filter(num -> num % 3 == 0)
                     .forEach(System.out::println);
	}
}
