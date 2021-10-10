// Find the common elements between two arrays - 4.

import java.util.*;
public class ArrayIntersection{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Integer a1[]={0,2,4,6,8,10,12,14,16,18,20,22,24,26,38,30};
		Integer a2[]={0,4,8,12,16,20,24,28,32,36,40};
		Set<Integer> s1 = new HashSet<Integer>(Arrays.asList(a1));
		Set<Integer> s2 = new HashSet<Integer>(Arrays.asList(a2));
		s1.retainAll(s2);
		System.out.println(s1);
		sc.close();
	}
}




















// https://stackoverflow.com/questions/34478006/how-to-add-an-array-into-set-properly