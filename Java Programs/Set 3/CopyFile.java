// Copy contents from one file to another in java - 17.

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;

public class CopyFile {
  public static void main(String[] args) throws IOException {
	  File sourceFile = new File("D:\\input.txt");
      File destFile = new File("D:\\newFile.txt");
      Files.copy(sourceFile.toPath(), destFile.toPath());
      System.out.println("Success");
  }
}