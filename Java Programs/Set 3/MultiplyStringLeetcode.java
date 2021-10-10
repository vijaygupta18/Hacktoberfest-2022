class Solution {
    
    public String multiply(String num1, String num2) {
        
        String finalvalue="";
        
        if(num1.equals("0")||num2.equals("0"))
            return "0";
        
        for(int i= num1.length()-1;i>=0;i--){
            
           int carry=0;
	            String finalr="";
	            int dig1=Integer.parseInt(String.valueOf(num1.charAt(i)));
	            
	            for(int j=num2.length()-1;j>=0;j--){
	                int dig2=Integer.parseInt(String.valueOf(num2.charAt(j)));
	                
	                int mul = dig1*dig2;
	                //System.out.println(mul+"m,"+j);
	                //System.out.println(carry+","+j);
	                mul=mul+carry;
	                
	                if(j!=0){
	                	carry=mul/10;
	                    mul=mul%10;
	                    
	                }
	                finalr=String.valueOf(mul)+finalr;
	            
	            }
	            //System.out.println(finalr);
	            //System.out.println(finalvalue);
	           finalvalue = sum(finalr,finalvalue,num1.length()-1-i);
	            
	            
	            
	        }
            
            
            
        
         
        return finalvalue;
    }
    public static String sum(String finalr,String finalvalue,int x){
        
    
        
        String a=finalvalue;
	        String b=finalr;
	        String v="";
	        a = reverse(a);
	        b = reverse(b);
	        
	        for(int j=1;j<=x;j++){
	            
	            b = "0" + b;
	        }
	        //System.out.println(b+"=b");
	        //addition code
	        int carry=0;
	        for(int i=0;i<a.length()||i<b.length();i++)
	        {
	        	
	            int s=0;
	            //condtions
	            if(i>=a.length())
	                s=Integer.parseInt(String.valueOf(b.charAt(i)));
	            else if(i>=b.length())
	                s=Integer.parseInt(String.valueOf(a.charAt(i)));
	            else
	     s=Integer.parseInt(String.valueOf(a.charAt(i)))+Integer.parseInt(String.valueOf(b.charAt(i)));
	            s=s+carry;
	            carry=s/10;
	            s=s%10;
	            
	            v=v+String.valueOf(s);
	            
	        }
	        if(carry!=0) {
	        	
	        	v=v+String.valueOf(carry);
	        	
	        	
	        }
	        //System.out.println("v="+reverse(v));
	        
	        return reverse(v);
        
        
    }
    public static String reverse(String x)
    {
        String f="";
        for(int i=0;i<x.length();i++){
            f=x.charAt(i)+f;
            
        }
        return f;
        
    }
}
