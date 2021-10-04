// Make a text file read only in java - 15.

import java.io.*;

public class ReadOnly {
	public static void main(String[] args) throws IOException {	
    	File myfile = new File("D:\\inputread.txt");
    	// Setting it to read only.
    	boolean flag = myfile.setReadOnly();	
    	if (flag==true)
    		System.out.println("File successfully converted to Read only mode!!");
    	else
    	    System.out.println("Unsuccessful Operation!!");
    	// Checking if it is read only.
    	if (myfile.canWrite())
    	   	System.out.println("File is writable.");
    	else
    		System.out.println("File is read only.");
    	// when trying to save changes in the file it asks to give a new name rather than saving it in the same file.
    	// Making it to a writable file again
    	myfile.setWritable(true);
    	if (myfile.canWrite())
    	   	System.out.println("File is writable.");
    	else
    		System.out.println("File is read only.");
    }
}






// https://beginnersbook.com/2014/05/how-to-make-a-file-read-only-in-java/