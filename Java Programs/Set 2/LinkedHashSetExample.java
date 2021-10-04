// Example program for LinkedHashSet in java - 23.

import java.util.*;

public class LinkedHashSetExample {
	public static void main(String[] args) {
		LinkedHashSet<String> linkedset = 
                           new LinkedHashSet<String>();  
        
        linkedset.add("A");  
        linkedset.add("B");  
        linkedset.add("C");  
        linkedset.add("D"); 
  		
  		linkedset.add("A"); 
        linkedset.add("E");  
  
        System.out.println("Size of LinkedHashSet = " +
                                    linkedset.size());  
        
        System.out.println("Original LinkedHashSet:" + linkedset);  
        
        System.out.println("Removing D from LinkedHashSet: " +
                            linkedset.remove("D"));  
        
        System.out.println("Trying to Remove Z which is not "+
                            "present: " + linkedset.remove("Z"));  
        
        System.out.println("Checking if A is present = " + 
                            linkedset.contains("A"));
        
        System.out.println("Updated LinkedHashSet: " + linkedset);

        System.out.println("Final LinkedHashSet.");
        for (String s : linkedset)
            System.out.print(s + ", ");
        System.out.println();
	}
}