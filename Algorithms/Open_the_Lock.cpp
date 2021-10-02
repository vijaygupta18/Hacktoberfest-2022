// Leetcode Question OPEN THE LOCK Technique
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dead(begin(deadends),end(deadends)),seen({"0000"});
        if(dead.find("0000")!=end(dead)) return -1;
        if(target == "0000") return 0;
        queue<string>q({"0000"});
        int n,min = 0;
        while(!q.empty()){
            n = size(q) , min++;
            for(int i=0;i<n;i++){
                auto cur_str = q.front(); q.pop();
                for(int j=0;j<4;j++){
                    for(auto adj_str : turn(cur_str,j)){
                        if(seen.find(adj_str) ==end(seen)&&dead.find(adj_str) == end(dead))
                        if(adj_str ==target) return min;
                        else q.push(adj_str), seen.insert(adj_str);
                        
                        }
                }
              
            }
        }
        
         return -1; 
    }
    vector<string> turn(string s,int i){
        vector<string>res(2,s);
        res[0][i]='0'+(res[0][i]-'0'+1)%10;
        res[1][i]='0'+(res[1][i]-'0'-1+10)%10;
        return res;
    }
};
