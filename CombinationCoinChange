import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
/**
 * Print all the Combinations of Change for a given Amount
 */
 class CoinChangeCombination {
 
	private static List<Integer> coins; 
	private static int count=0;
 
	
	private static void init() {
		coins = new ArrayList<Integer>();
		coins.add(1);
		coins.add(3);
		coins.add(5);
		coins.add(9);
		coins.add(10);
		coins.add(14);
                coins.add(18);
		coins.add(23);
	}
 
	/**
	 * Prints all comninations of the coin change
	 */
	public static void coinCombinations(int amount,int index,LinkedList<Integer> list)
	{
		if(amount==0)
		{
			count++;
                        System.out.println(list);
                          
                      
			return ;
		}
 
		if(amount < 0)
			return ;
 
		for(int i=index ; i < coins.size();i++)
		{
			int coin = coins.get(i);
			if(amount >= coin)
			{
				list.add(coin);
				coinCombinations(amount - coin ,i,list );
				list.removeLast();
 
			}
		}
	}
 
	public static void main(String[] args) {
           int amount = 175;
		init();
		coinCombinations(amount,0,new LinkedList<Integer>());
		//System.out.println("Number of Combinations :" + count);
            
	}
}
