class Solution {
public:
    int recurse(string s, int idx,vector<int> &dp){
        if(idx>=s.size())
            return 1;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];
        
        int a = recurse(s,idx+1,dp);
        int b=0;
        if(idx+1<s.size()){
            string temp="";
            temp+=s[idx];
            temp+=s[idx+1];
            if(stoi(temp)<=26){
                b=recurse(s,idx+2,dp);
            }
        }
        return dp[idx]=a+b;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return recurse(s,0,dp);
    }
};