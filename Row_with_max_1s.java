import java.util.Scanner;

public class Row_with_max_1s {

    public static void maxs (int a[][])
    {
        int c=0;
        for (int j=0;j<a[0].length;j++)
        {
            for (int i=0;i<a.length;i++)
            {
                if (a[i][j]==1)
                {
                    System.out.println(i);
                    ++c;
                    break;
                }
            }if (c==1) break;
        }
    }







    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int a[][]= new int [4][4];
        for (int i =0;i<4;i++)
        {
            for (int j=0;j<4;j++)
            a[i][j]= sc.nextInt();
        }
        for (int i =0;i<4;i++)
        {
            for (int j=0;j<4;j++)
            System.out.print(a[i][j]+" ");
            System.out.println();
        }
        maxs(a);
        sc.close();
    }
    
}
