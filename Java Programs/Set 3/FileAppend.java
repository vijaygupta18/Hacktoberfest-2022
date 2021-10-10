// Append text to a file in java - 1.
import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class FileAppend {
   public static void main( String[] args ) {
      try {
        String data = "Hello, Pranav Suryadevara.";
        File f = new File("D:\\input1.txt");
        if(!f.exists()) {
        	f.createNewFile();
        }

        FileWriter fw = new FileWriter(f, true);
        BufferedWriter br = new BufferedWriter(fw);
        PrintWriter pr = new PrintWriter(br);
        pr.println(data);
        pr.close();
        br.close();
        fw.close();
        System.out.println("Done");
      	}
      	catch(IOException e){
        	e.printStackTrace();
      	}
   }
}