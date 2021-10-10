// Count the number of lines, words and characters in a text file - 2.

import java.io.*;

public class LineWordChar {
	public static void main(String[] args) {
        int charCount = 0;
	    int wordCount = 0;
	    int lineCount = 0;
	    try {
	        BufferedReader reader = new BufferedReader(new FileReader("D:\\input1.txt"));
	        String currentLine = reader.readLine();
	        while (currentLine != null) {
	            lineCount++;
				String[] words = currentLine.split(" ");
	 			wordCount = wordCount + words.length;
	            for (String word : words)
	            	charCount = charCount + word.length();
				currentLine = reader.readLine();
	        }
	        System.out.println("Number Of Chars : "+charCount);	             
	        System.out.println("Number Of Words : "+wordCount);
	        System.out.println("Number Of Lines : "+lineCount);
	        reader.close();
	    } 
	    catch (IOException e) {
	    	e.printStackTrace();
		}
	}
}