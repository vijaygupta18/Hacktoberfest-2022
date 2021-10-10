// Leetcode Problem : 29 Divide Two Integers - https://leetcode.com/problems/divide-two-integers/
class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend == INT_MIN && divisor==-1)
            return INT_MAX;

        long dvd = labs(dividend);
        long dvs = labs(divisor);
        long quot = 0, temp=0;

        int sign  =  (dividend > 0) == (divisor > 0 ) ? 1 : -1 ;

        for(int i=31; i>=0; i--)
        {
            if(temp + (dvs<<i) <=  dvd)
            {
                temp+=(dvs<<i);
                quot+=(1<<i);
            }
        }

        return sign*quot;
    }
};
