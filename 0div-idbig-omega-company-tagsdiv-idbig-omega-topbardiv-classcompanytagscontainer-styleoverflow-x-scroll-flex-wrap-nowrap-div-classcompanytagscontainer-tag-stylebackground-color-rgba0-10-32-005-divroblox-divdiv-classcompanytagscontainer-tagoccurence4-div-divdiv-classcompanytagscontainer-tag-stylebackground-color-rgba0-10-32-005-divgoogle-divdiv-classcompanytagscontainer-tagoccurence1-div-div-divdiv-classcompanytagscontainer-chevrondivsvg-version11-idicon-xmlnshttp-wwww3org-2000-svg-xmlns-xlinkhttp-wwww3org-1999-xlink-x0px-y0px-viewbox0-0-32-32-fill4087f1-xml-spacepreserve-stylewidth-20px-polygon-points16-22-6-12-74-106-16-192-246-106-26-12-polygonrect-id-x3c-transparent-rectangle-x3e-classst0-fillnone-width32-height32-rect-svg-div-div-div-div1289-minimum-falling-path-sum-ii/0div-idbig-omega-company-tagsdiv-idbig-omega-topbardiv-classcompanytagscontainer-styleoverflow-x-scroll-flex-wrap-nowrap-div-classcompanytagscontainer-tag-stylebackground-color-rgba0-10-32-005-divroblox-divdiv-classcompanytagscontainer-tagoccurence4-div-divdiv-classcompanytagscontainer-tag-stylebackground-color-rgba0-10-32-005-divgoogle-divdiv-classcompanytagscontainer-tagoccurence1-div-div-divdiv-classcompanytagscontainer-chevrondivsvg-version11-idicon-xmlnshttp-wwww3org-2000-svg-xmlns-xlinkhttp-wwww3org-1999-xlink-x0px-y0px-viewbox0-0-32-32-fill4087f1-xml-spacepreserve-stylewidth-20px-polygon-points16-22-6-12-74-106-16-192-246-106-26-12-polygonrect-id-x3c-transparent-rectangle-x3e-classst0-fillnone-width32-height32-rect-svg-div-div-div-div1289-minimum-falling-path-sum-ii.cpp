class Solution {
public:
    int recurse(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp)
    {
     if(i==grid.size()||j==grid.size()) return 0;  
     if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
     for(int k=0;k<grid.size();k++)
     {
           if(k!=j) mini=min(mini,recurse(i+1,k,grid,dp));
     }
        return dp[i][j]=grid[i][j]+mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),mini=INT_MAX;
        if(n==1) return grid[0][0];
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            mini=min(mini,recurse(0,i,grid,dp));
        }
        return mini;
    }
};