class Solution {
public:
    
    int reverse(int x) {
        
        int n=x;
        int rev=0;
        while(x!=0){
            int pop = x%10;
            
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop >INT_MAX / 10  )) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop <INT_MIN / 10  )) return 0;
            
            rev = (rev*10)+pop;
            
            
            
            x/=10;
        }
        // if(abs(rev) > INT_MAX/10) return 0;
        // else
        return rev;
        
        
    }
};
