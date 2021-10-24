/*Matrix A--mxn  Matrix B--pxq,
 if n==p then we can perform matrix multliplication
 Resultant Matrix C--mxq */
import java.util.*;
class MatrixMulLe11
{
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
System.out.println("Enter no of rows and columns of A:");
int m=sc.nextInt();
int n=sc.nextInt();
System.out.println("Enter no of rows and columns of b:");
int p=sc.nextInt();
int q=sc.nextInt(),i,j,k;
if(n!=p)
{
System.out.println("Multiplication not possible..!!");
}
else
{
int[][] a=new int[m][n];
int[][] b=new int[p][q];
int[][] c=new int[m][q];
System.out.println("Enter elements of matrix A:");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
a[i][j]=sc.nextInt();

System.out.println("Enter elements of matrix B:");
for(i=0;i<p;i++)
for(j=0;j<q;j++)
b[i][j]=sc.nextInt();

//Matrix multiplication
for(i=0;i<m;i++)
{
for(j=0;j<q;j++)
{
c[i][j]=0;
for(k=0;k<n;k++)
c[i][j]=c[i][j]+a[i][k]*b[k][j];
}
}
System.out.println("Resultant Matric C:");
for(i=0;i<m;i++)
{
for(j=0;j<q;j++)
System.out.print(c[i][j]+" ");
System.out.println(" ");
}
}
}
}
