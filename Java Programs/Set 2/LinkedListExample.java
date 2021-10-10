// Java Program for an ArrayList Example - 20.

import java.util.*;

public class LinkedListExample {
	public static void main(String[] args) {
		LinkedList<String> ll = new LinkedList<String>();
  
        // Adding elements to the linked list.
        ll.add("A");
        ll.add("B");
        ll.addLast("C");
        ll.addFirst("D");

        // add at an index postion.
        ll.add(2, "E");
        System.out.println(ll);
  
        ll.remove("B");
        System.out.println(ll);
        // remove at an index position.
        ll.remove(3);
        System.out.println(ll);
        ll.removeFirst();
        System.out.println(ll);
        ll.removeLast();
        System.out.println(ll);
        
        ll.add("A");
        ll.add("B");
        ll.addLast("C");
        ll.addFirst("D");
        System.out.println(ll);
        
        ll.clear();
        System.out.println(ll);
             
        ll.add("Pranav"); 
        ll.add("Suryadevara"); 
        ll.add(1, "For");
        System.out.println(ll);
        // change the element value at a position.
        ll.set(1, "Sergio");
        System.out.println(ll);
        
	}
}