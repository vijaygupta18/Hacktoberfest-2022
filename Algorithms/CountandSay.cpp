// Leetcode Problem 38. Count and Say https://leetcode.com/problems/count-and-say/
class Solution {
public:
    
    inline string findCount(string s)
    {
        string res="";
        int size = s.size(), i=0;
        while(i<size)
        {
            int count=1;
            while(i<size-1 && s[i]==s[i+1])
            {
                count++;
                i++;
            }
            
            res = res + to_string(count) + s[i];
            i++;
        }
        return res;
    }
    
    string countAndSay(int n) {
        if(n==1)
            return "1";
        
        string res="1";
        for(int i=2; i<=n; i++)
            res = findCount(res);
        return res;
    }
};
