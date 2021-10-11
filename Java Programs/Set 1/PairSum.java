// Pair of elements that add up to a given sum

import java.util.*;

public class PairSum{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int sum = sc.nextInt();
		int n = sc.nextInt();
		int a[] = new int[n];
		for (int i = 0;i < n; i++)
			a[i] = sc.nextInt();

		HashSet<Integer> hs = new HashSet<Integer>();
		ArrayList<Pair> list = new ArrayList<Pair>();
		for (int i = 0;i < n; i++){
			int x = sum - a[i];
			if (hs.contains(x)){
				list.add(new Pair(x, a[i]));
				hs.remove(x);
			}
			else{
				hs.add(a[i]);
			}
		}
		Iterator itr=list.iterator();  
		while(itr.hasNext()){ 
			System.out.println(((Pair) itr.next()).getPair());  
		} 
		sc.close();
	}
}

class Pair{
	int x;
	int y;
	Pair(int a, int b){
		this.x=a;
		this.y=b;
	}
	public  String getPair(){
		return "<"+x+", "+y+">";
	}
}