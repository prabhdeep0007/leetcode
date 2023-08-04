class Solution {
public:
    bool solve(unordered_map<string,int>&m,int ind,string &s,vector<int> &dp)
    {
        if(ind==s.size()) return true;
        if(dp[ind]!=-1) return dp[ind];
        string temp="";
        for(int i=ind;i<s.size();i++)
        {
            temp+=s[i];
            if(m[temp] && solve(m,i+1,s,dp))
            {
                return dp[ind]=1;
            }
        }
        return dp[ind]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>m;
        vector<int> dp(s.size(),-1);
        for(auto i:wordDict)
        {
           m[i]=1;
        }
       return solve(m,0,s,dp);
        
    }
};