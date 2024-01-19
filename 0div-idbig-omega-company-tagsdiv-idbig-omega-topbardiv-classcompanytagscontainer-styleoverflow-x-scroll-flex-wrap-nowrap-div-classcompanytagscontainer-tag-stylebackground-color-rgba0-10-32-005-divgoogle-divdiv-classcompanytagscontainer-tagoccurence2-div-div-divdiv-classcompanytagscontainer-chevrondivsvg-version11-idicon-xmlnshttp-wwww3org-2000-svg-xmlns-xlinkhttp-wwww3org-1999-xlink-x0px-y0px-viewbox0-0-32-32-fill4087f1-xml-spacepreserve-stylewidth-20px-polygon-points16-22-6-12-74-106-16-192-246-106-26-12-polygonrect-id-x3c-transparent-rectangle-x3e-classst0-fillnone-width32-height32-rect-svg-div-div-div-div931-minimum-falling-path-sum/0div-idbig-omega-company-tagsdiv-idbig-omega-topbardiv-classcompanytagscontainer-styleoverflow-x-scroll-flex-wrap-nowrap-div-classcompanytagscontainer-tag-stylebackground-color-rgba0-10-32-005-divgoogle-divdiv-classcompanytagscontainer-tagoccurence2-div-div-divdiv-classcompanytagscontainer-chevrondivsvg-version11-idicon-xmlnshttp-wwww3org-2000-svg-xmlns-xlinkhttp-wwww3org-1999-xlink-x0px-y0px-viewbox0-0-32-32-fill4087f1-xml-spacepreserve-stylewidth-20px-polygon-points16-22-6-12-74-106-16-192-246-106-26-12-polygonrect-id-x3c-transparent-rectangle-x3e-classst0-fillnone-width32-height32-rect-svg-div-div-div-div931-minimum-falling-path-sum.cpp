class Solution {
public:
    // int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    // {    
    //     if(j<0 || j>=matrix[0].size()) return +1e8;
    //     if(i==0) return matrix[0][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int up=matrix[i][j]+solve(i-1,j,matrix,dp);
    //     int left=matrix[i][j]+solve(i-1,j-1,matrix,dp);
    //     int right=matrix[i][j]+solve(i-1,j+1,matrix,dp);
    //     return dp[i][j]=min(up,min(left,right));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int mini=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++)
        {
           dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
            int left=INT_MAX,right=INT_MAX;
            int up=matrix[i][j]+dp[i-1][j];
            if(j>0)  left=matrix[i][j]+dp[i-1][j-1];
            if(j<m-1)right=matrix[i][j]+dp[i-1][j+1];
            dp[i][j]=min(up,min(left,right));
            }
        }
          for(int j=0;j<m;j++)
        {
            mini=min(mini,dp[n-1][j]);
        }
    return mini;
    }
};