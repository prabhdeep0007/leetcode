class Solution {
public:
    int minInsertions(string s) {
        string s2(s.rbegin(),s.rend());
        int n=s.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else{
                     
                      dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
            
        return s.size()-dp[n][m];
    }
};