// Example program for HashSet in java - 22.

import java.util.*;  

public class HashSetExample{  
    public static void main(String args[]){  
        
        HashSet<String> set=new HashSet<String>();  
        set.add("Pranav");  
        set.add("Surya");  
        set.add("Aneesh");  
        set.add("Kartheek");  
        System.out.println("Initial Set "+set);  
        set.remove("Surya");  
        System.out.println("After Remvoing surya"+set);  
        
        HashSet<String> set1=new HashSet<String>();  
        set1.add("Ajay");  
        set1.add("Vijay");  
        set.addAll(set1);  
        System.out.println("Updating with another set: "+set);  
        set.removeAll(set1);  
        System.out.println("Deleting all the elements from another set "+set);  
        set.removeIf(str->str.contains("Vijay"));    
        System.out.println("After removeIf "+set);  
        set.clear();  
        System.out.println("Clearing set "+set);  
    }  
}  