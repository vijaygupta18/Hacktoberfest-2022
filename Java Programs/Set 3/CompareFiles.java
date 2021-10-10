// Compare two files in java - 22.

public class CompareFiles{
	public static void main(String[] args) throws IOException {   
		BufferedReader br1 = new BufferedReader(new FileReader("D:\\file1.txt"));
    	BufferedReader br2 = new BufferedReader(new FileReader("D:\\file2.txt"));
    	String line1 = br1.readLine();
    	String line2 = br2.readLine();
    	boolean areEqual = true;
    	int lineNum = 1;
    	while (line1 != null || line2 != null) {
			if(line1 == null || line2 == null) {
				areEqual = false;
    	    	break;
    	    }
    	    else if(! line1.equalsIgnoreCase(line2)) {
    	        areEqual = false;
    	    	break;
			}
    	    line1 = br1.readLine();
    	    line2 = br2.readLine();
    	    lineNum++;
    	}
    	if(areEqual) 
    	    System.out.println("Two files have same content.");
		else {
    		System.out.println("Two files have different content. They differ at line "+lineNum);
    	    System.out.println("File1 has "+line1+" and File2 has "+line2+" at line "+lineNum);
    	}
		br1.close();
    	br2.close();
    }
}