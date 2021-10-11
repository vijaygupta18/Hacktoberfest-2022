// Find the most frequent element in an Array - 18.

import java.util.*;
import java.util.Map.Entry;

public class MostFrequentElement {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// int n = sc.nextInt();
		// int[] a = new int[n];
		// for (int i = 0; i < n; i++)
		// 	a[i] = sc.nextInt();

		int a[] = {1, 5, 2, 1, 3, 2, 1};
		int n = a.length;

		Map<Integer, Integer> hm = new HashMap<Integer, Integer>();
        for(int i = 0; i < n; i++){
            int k = a[i];
            if(hm.containsKey(k)){
                int c = hm.get(k);
                c++;
                hm.put(k, c);
            }
            else   {
                hm.put(k, 1);
            }
        }

        int max = 0, ans = 0;
        for(Map<Integer, Integer> val : hm.entrySet()){
            if (max < val.getValue()) {
                ans = val.getKey();
                max = val.getValue();
            }
        }
        System.out.print("Most Repeated Element is " + ans + " : " + max + " times." );
		sc.close();
	}
}