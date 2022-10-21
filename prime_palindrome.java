import java.util.*;
class prime_palindrome
{
    void showPrimePal()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter m");
        int m=sc.nextInt();
        System.out.println("Enter n");
        int n=sc.nextInt();
        int c=0;
        if(m>n ||n>3000)
        {
        System.out.println("out of range");
    }
        else
        {
          System.out.println(" prime palindrome integers are");
          while(m<=n)
          {
         if(PrimePal(m)==true)
        {
            if(c==0)
            System.out.print(m);
            else
            System.out.print(","+m);
            c++;
        }
            m++;
    }
       System.out.println("\nfrequency of prime palindrome integer="+c); 
    }
}
    boolean PrimePal(int x)
    {
        boolean flag= false;
        int c=0,rev=0,d=0,cp=0;
        cp=x;
        for(int i=1;i<=x;i++)
        {
            if(x%i==0)
            {
                c++;
            }
        }
        if(c==2)
        {
            while(x>0)
            {
                d=x%10;
                rev=rev*10+d;
                x=x/10;
            }
        
            if(rev==cp)
            flag=true;
        }
            return flag;
        }
        public void main()
        {
            prime_palindrome obj = new prime_palindrome();
            obj.showPrimePal();

    }
}


        