import java.util.Scanner;
class Subsequence{
	public int longestPalinSubseq(String S)
    {
        StringBuilder temp = new StringBuilder(S);
        temp.reverse();
        int length=S.length();
        String rev=temp.toString();
        int[][] store=new int[length+1][length+1];
        for(int i=0;i<=length;i++){
            for(int j=0;j<=length;j++){
                if(i==0 || j==0){
                    store[i][j]=0;
                }
                else if(S.charAt(i-1)==rev.charAt(j-1)){
                    store[i][j]=1+store[i-1][j-1];
                }
                else{
                    store[i][j]=Math.max(store[i-1][j],store[i][j-1]);
                }
            }
        }
        return store[length][length];
    }
}
public class longestPalindrome {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		System.out.println("Enter number of inputs");
		int n=in.nextInt();
		while(n!=0){
			String s=in.next();
			Subsequence obj=new Subsequence();
			System.out.println(obj.longestPalinSubseq(s)); //prints length of longest subsequence for the given string
		}
		
	}

}
