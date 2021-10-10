// Java Program for an ArrayList Example - 19.

import java.util.*;

public class ArrayListExample {
	public static void main(String[] args) {
		List<Integer> numbers = new ArrayList<>(Arrays.asList(5,4,3,1,2)); 
		Iterator<Integer> iterator = numbers.iterator();
		System.out.println("Initial ArrayList: ");
		while(iterator.hasNext()) {
		    System.out.print(iterator.next() + " ");
		}
		System.out.println("\nSize: " + numbers.size());
		Collections.sort(numbers);
		System.out.println("Sorted: " + numbers);
		
		numbers.add(10);
		numbers.add(20);
		numbers.add(25);
		numbers.add(17);
        System.out.println("List: " + numbers);
        
        // removing by index.
        numbers.remove(3);
        
        // remove by value.
        numbers.remove(new Integer(20));
        System.out.println("List: " + numbers);
        
        // clearing the numbers.
        numbers.clear();
        System.out.println("List: " + numbers);
	}
}