// Spiral Matrix Program - 8.

import java.util.*;

public class SpiralMatrix {
	public static void main(String[] args) {
        int i=0;
        int j=0;
        int matrix[][]={{1,2,3},{4,5,6},{7,8,9}};  
        int R=matrix.length-1;
        int C=matrix[0].length-1;

        while(i<=R && j<=C){
            for(int k=j;k<=C;k++)
                System.out.print((matrix[i][k]) + " ");
            i++;
            
            for(int k=i;k<=R;k++)
                System.out.print((matrix[k][C]) + " ");
            C--;
            
            if(i<=R){
                for(int k=C;k>=j;k--)
                    System.out.print((matrix[R][k]) + " ");
                R--;
            }
            if(j<=C){
                for(int k=R;k>=i;k--)
                    System.out.print((matrix[k][j]) + " ");
                j++;
            }
        }
	}
}


