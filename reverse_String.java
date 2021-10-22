public class reverse_String 
{
    static String reverse(String s1)
    {
        int i,l,r,n;
        char[] in = s1.toCharArray();
        n=s1.length()-1;
        for(l=0,r=n;l<r;l++,r--)
        {
            char temp=in[l];
            in[l]=in[r];
            in[r]=temp;
        }
        return String.copyValueOf(in);
    }
    
    public static void main(String args[])
    {
        String s1="My First Java Code";
        System.out.println(reverse(s1));
    }
}
