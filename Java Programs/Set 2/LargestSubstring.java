// Find the largest substring with unique characters - 26.

import java.util.*;

public class LargestSubstring {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		Map<Character, Integer> visited = new HashMap<>();
	    String output = "";
	    for (int start = 0, end = 0; end < input.length(); end++) {
	        char curr = input.charAt(end);
	        if (visited.containsKey(curr)) {
	            start = Math.max(visited.get(curr)+1, start);
	        }
	        if (output.length() < end - start + 1) {
	            output = input.substring(start, end + 1);
	        }
	        visited.put(curr, end);
	    }
        System.out.print(output);
		sc.close();
	}	
}