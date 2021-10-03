import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
 {
	public static void main (String[] args)
	 {
	     Scanner sc = new Scanner(System.in);
	     int T = sc.nextInt();
	     while(T-- > 0) {
	         char[] s = sc.next().toCharArray();
	         Arrays.sort(s);
	         boolean used[] = new boolean[s.length];
	         StringBuilder curr = new StringBuilder();
	         StringBuilder res = new StringBuilder();
	         helper(s, used, curr, res);
	         System.out.println(res.toString().trim());
	     }
 	 }
 	 public static void helper(char[] s, boolean[] used, StringBuilder curr, StringBuilder res) {
 	     if(curr.length() == s.length) {
 	         res.append(curr.toString()).append(" ");
 	         return;
 	     }
 	     for(int i = 0 ; i < s.length ; i++) {
 	         if(used[i]) continue;
 	         used[i] = true;
 	         curr.append(s[i]);
 	         helper(s, used, curr, res);
 	         curr.setLength(curr.length() - 1);
 	         used[i] = false;
 	     }
 	 }
}