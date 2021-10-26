package CP.DP;

public class CutRod {

    public static void main(String[] args) {

        int[] prices = {3,5,8,9,10,17,17,20};

        int n = prices.length;

        int[] values = new int[n+1];

        values[0] = 0;

        for(int i=1;i<=n;i++){
            int max = Integer.MIN_VALUE;

            for(int j=0;j<i;j++){
                max = Math.max(max, prices[j] + values[i-j-1]);
            }

            values[i] = max;

        }

        System.out.println(values[n]);


    }


}
