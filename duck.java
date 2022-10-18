import java.util.*;
class duck
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the no.");
        int n=sc.nextInt();
        int x=n;int k=0,t=0;
        while(n!=0)
        {
            int d=n%10;
            k++;
            n=n/10;
        }
        int y=(int)(x%Math.pow(10,k));
        if(y==0)
        {
            System.out.println("Not duck no.");
        }
        else
        {
            while(x!=0)
            {
                int e=x%10;
                if(e==0)
                {
                    t++;
                    break;
                }
                x=x/10;
            }
            if(t>0)
            {
                System.out.println(" duck no.");
            }
            else
            {
                System.out.println("Not duck no.");
        }
    }
}
}

                
            
            
            
            
            
            
            
        
        