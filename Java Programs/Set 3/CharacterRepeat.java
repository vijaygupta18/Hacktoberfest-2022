// Find the first Repeated and Non - Repeated Character in Java - 7.

import java.util.*;

public class CharacterRepeat {	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.nextLine();
		ArrayList a = new ArrayList();
		int count = 0;
		for (int i = 0; i < x.length(); i++){
			if(!a.contains(x.charAt(i)))
				a.add(x.charAt(i));
			else{
				count = count + 1;
				if (count == 1)
					System.out.println("First Repeated Character is " + x.charAt(i));
				a.remove(new Character(x.charAt(i)));
			}
		}
		System.out.println("First Non - Repeated Character is " + a.get(0));
		sc.close();
	}
}