class Solution {
public:
    int solve(int i,int j,string &s1,string&s2,vector<vector<int>>&dp)
    {
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+solve(i-1,j-1,s1,s2,dp);
        int a=solve(i,j-1,s1,s2,dp);
        int b=solve(i-1,j,s1,s2,dp);
        return dp[i][j]=max(a,b);
    }
    int longestPalindromeSubseq(string s) {
        string s2(s.rbegin(),s.rend());
        int n=s.size(),m=s2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,s2,dp);
    }
};