class Solution {
public:
    // int solve(int i,int j,string &s1,string&s2,vector<vector<int>>&dp)
    // {
    //     if(i<0||j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s1[i]==s2[j]) return dp[i][j]=1+solve(i-1,j-1,s1,s2,dp);
    //     int a=solve(i,j-1,s1,s2,dp);
    //     int b=solve(i-1,j,s1,s2,dp);
    //     return dp[i][j]=max(a,b);
    // }
    int longestPalindromeSubseq(string s) {
        string s2(s.rbegin(),s.rend());
        int n=s.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else{
                     int a=dp[i][j-1];
                     int b=dp[i-1][j];
                      dp[i][j]=max(a,b);
                }
            }
        }
            
        return dp[n][m];
    }
};