public class knapsack_01_memoization {

	public static void main(String[] args) {
        int val[] = new int[] { 60, 100, 120 };
        int wt[] = new int[] { 10, 20, 30 };
        int W = 50;
        int n = val.length;

        int dp[][] = new int[n+1][W+1];
		for(int i=0; i<dp.length; i++) {
			for(int j=0; j<dp[0].length; j++) {
				dp[i][j] = -1;
			}
		}

        System.out.println(knapSack(wt, val, W, n, dp)); //recursive call
	}

	private static int knapSack(int[] wt, int[] val, int W, int n, int dp[][]) {
		//base case
		if(n==0 || W==0) {
			return 0;
		}

		if(dp[n][W] != -1) {
			return dp[n][W];
		}

		if(wt[n-1] <= W) {
			dp[n][W] = Math.max(val[n-1] + knapSack(wt, val, W-wt[n-1], n-1, dp), knapSack(wt, val, W, n-1, dp));
			return dp[n][W];
		}
		else {  // if(wt[n-1] > W)
			dp[n][W] = knapSack(wt, val, W, n-1, dp);  //i.e. we don't include this and move on
			return dp[n][W];
		}
	}
} 