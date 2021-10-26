package CP.DP;

import java.util.Arrays;

public class LongestCommonSubs {

    public static void main(String[] args) {

        String s1 = "AGGTAB";
        String s2 = "GXTXAYB";

        char[] x = s1.toCharArray();
        char[] y = s2.toCharArray();

        int m = x.length;
        int n = y.length;

        StringBuilder s = new StringBuilder();

        int[][] L = new int[m+1][n+1];

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i == 0 || j == 0){
                    L[i][j] = 0;
                }
                else if(x[i-1] == y[j-1]){
                    L[i][j] = L[i-1][j-1] + 1;

                    if((L[i-1][j] == L[i][j] - 1) && (L[i][j-1] == L[i][j] - 1)) {

                        if(i==1 && j==5){
                            System.out.println(L[i][j-1] + " " + L[i][j]);
                        }

                        //System.out.println(i + " " + j);
                        s.append(x[i - 1]);
                    }
                }
                else{
                    L[i][j] = Math.max(L[i-1][j], L[i][j-1]);
                }
            }
        }

        System.out.println(Arrays.deepToString(L));

        System.out.println(L[2][1]);

        System.out.println(L[m][n]);
        System.out.println(s);
    }

}
