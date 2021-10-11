// Write a java program to sort a text file in java - 24.

import java.util.*;


public class SortATextFile {
    public static void main(String[] args)
    {
        BufferedReader reader = null; 
        BufferedWriter writer = null;
        ArrayList<String> lines = new ArrayList<String>();
 
        try{
            reader = new BufferedReader(new FileReader("D:\\input.txt"));
 			String currentLine = reader.readLine();
            while (currentLine != null){
                lines.add(currentLine);
                currentLine = reader.readLine();
            }
            Collections.sort(lines);
            writer = new BufferedWriter(new FileWriter("D:\\output.txt"));
            for (String line : lines){
                writer.write(line);
                writer.newLine();
            }
        }
        catch (IOException e){
            e.printStackTrace();
        }
        finally{
            try{
                if (reader != null){
                    reader.close();
                }
                if(writer != null){
                    writer.close();
                }
            }
            catch (IOException e){
                e.printStackTrace();
            }
        }
    }
}


// https://javaconceptoftheday.com/how-to-sort-a-text-file-in-java/