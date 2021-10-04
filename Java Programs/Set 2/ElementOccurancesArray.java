// Count all the occurances of a an element in an array - 27.

import java.util.*;

public class ElementOccurancesArray {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		HashMap<Integer, Integer> hm = new HashMap<>();
		
		for (int i = 0; i < n; i++){
			a[i]=sc.nextInt();
			hm.put(a[i], hm.getOrDefault(a[i], 0) + 1);
		}

		System.out.println("Method 1");
		Iterator hmIterator = hm.entrySet().iterator();
		while (hmIterator.hasNext()) {
            Map.Entry mapElement = (Map.Entry)hmIterator.next();
            System.out.println(mapElement.getKey() + " : " + mapElement.getValue());
        }

		System.out.println("Method 2");
		for (Map.Entry x : hm.entrySet()) {
            System.out.println(x.getKey() + " : " + x.getValue());
        }


		System.out.println("Method 3");
		hm.forEach((k, v) -> System.out.println(k + " : " + v));
		sc.close();
	}
}