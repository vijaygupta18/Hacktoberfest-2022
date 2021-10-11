// Find all Permutations of a String - 4.

import java.util.*;

public class StringPermutations {    
	public static void main(String[] args) {
		 String str = "abc";    
	        int len = str.length();    
	        System.out.println("All the permutations of the string are: ");    
	        generatePermutation(str, 0, len);    
	}    
	        
	    public static void generatePermutation(String str, int start, int end)    
	    {     
	        if (start == end-1)    
	            System.out.println(str);    
	        else    
	        {    
	            for (int i = start; i < end; i++)    
	            {    
	       
	                str = swapString(str,start,i);   
	                generatePermutation(str,start+1,end);        
	                str = swapString(str,start,i);    
	            }    
	        }    
	}

	public static String swapString(String a, int i, int j) {    
	        char[] b =a.toCharArray();    
	        char ch;    
	        ch = b[i];    
	        b[i] = b[j];    
	        b[j] = ch;    
	        return String.valueOf(b);    
	}
}
