class Solution {
public:
    int solve(string &s, unordered_map<string,int> &m,int i,vector<int>&dp,int &n)
    {
        if(i>=n)return 0;
        if(dp[i]!=-1) return dp[i];
        int not_Take=1+solve(s,m,i+1,dp,n),take=n+1;
        string t="";
        for(int ind=i;ind<n;ind++)
        {
         t+=s[ind];
            if(m[t]) take=min(take,solve(s,m,ind+1,dp,n));
        }
        return dp[i]=min(take,not_Take);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
     unordered_map<string,int> m;
        int n=s.size();
    for(auto i:dictionary)
    {
        m[i]=1;
    }
        string t="";
        vector<int> dp(n+1,-1);
     return solve(s,m,0,dp,n);
    }
};