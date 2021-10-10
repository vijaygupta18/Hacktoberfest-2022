// Find the most repeated word in java - 30.

import java.util.*;
import java.io.*;

public class MostRepeatedWord {
	public static void main(String[] args) throws IOException {
		String line, word = "";
		int count = 0, max = 0;
		ArrayList<String> words = new ArrayList<String>(); 

		FileReader file = new FileReader("hello.txt");
		BufferedReader br = new BufferedReader(file);
		while((line = br.readLine()) != null) {
			// splits based on whitespace, comma, fullstop or brackets.
            String string[] = line.toLowerCase().split("([,.\\s]+) ");    
            for(String s : string){    
                words.add(s);    
            }    
        }
        System.out.println("List of All words including repetitions.");
        for(int i = 0; i < words.size(); i++){
        	System.out.print(words.get(i)+" ");
        }
        System.out.println();
        for(int i = 0; i < words.size(); i++){    
            count = 1;    
            for(int j = i+1; j < words.size(); j++){    
                if(words.get(i).equals(words.get(j))){    
                    count++;    
                }     
            }    
            if(count > max){    
                max = count;    
                word = words.get(i);    
            }    
        }    
            
        System.out.println("Most repeated word: " + word);    
        br.close(); 
	}	
}