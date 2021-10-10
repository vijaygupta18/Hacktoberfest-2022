import java.lang.*;
import java.util.*;

public class ArrayList_ {
    public static void main(String[] args) {
        // YOUR CODE GOES HERE
        // Please take input and print output to standard input/output (stdin/stdout)
        // DO NOT USE ARGUMENTS FOR INPUTS
        // E.g. 'Scanner' for input & 'System.out' for output
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> ob=new ArrayList<Integer>();
        while(sc.hasNext())
        {
            int a=Integer.parseInt(sc.next());
            if(a<0){
                break;
            }
            else
                ob.add(a);
                
        }
        sc.close();
        for(int i=ob.size()-1; i>=0;i--)
            System.out.print(ob.get(i)+" ");
        
    }
}
