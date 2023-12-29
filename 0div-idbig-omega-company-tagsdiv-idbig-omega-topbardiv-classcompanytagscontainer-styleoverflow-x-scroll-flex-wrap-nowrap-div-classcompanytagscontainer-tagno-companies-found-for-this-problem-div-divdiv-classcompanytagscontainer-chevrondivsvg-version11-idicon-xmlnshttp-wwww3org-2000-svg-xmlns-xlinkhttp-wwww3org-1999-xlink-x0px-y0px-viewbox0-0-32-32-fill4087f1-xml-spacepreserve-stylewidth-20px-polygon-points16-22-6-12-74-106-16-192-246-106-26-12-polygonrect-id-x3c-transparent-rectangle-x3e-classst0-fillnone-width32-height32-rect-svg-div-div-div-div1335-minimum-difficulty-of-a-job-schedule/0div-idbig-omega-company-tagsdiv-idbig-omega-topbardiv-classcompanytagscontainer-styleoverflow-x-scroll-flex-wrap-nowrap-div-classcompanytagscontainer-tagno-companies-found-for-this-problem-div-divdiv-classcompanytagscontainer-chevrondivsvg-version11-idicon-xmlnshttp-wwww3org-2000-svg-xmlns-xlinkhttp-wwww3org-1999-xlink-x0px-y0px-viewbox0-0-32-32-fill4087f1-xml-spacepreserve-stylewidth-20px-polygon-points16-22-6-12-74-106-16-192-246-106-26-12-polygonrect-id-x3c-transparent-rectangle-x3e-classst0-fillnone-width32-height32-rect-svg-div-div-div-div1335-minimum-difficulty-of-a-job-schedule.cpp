class Solution {
public:
    int solve(int i,vector<int>& jobDifficulty,int d,int &n, vector<vector<int>> &dp)
    {
        if(d==1)
        {  int maxi=0;
            
          for(int j=i;j<n;j++)
             {
                maxi=max(maxi,jobDifficulty[j]);
             }
         return maxi;
        }
        int maxi=0,mini=INT_MAX;
        d=d-1;
     if(dp[i][d]!=-1)return dp[i][d];
     for(int j=i;j<n-d;j++)
     {
         maxi=max(maxi,jobDifficulty[j]);
         mini=min(mini,maxi+solve(j+1,jobDifficulty,d,n,dp));
     }
    return dp[i][d]=mini;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        vector<vector<int>> dp(n,vector<int>(d,-1));
        int ans=solve(0,jobDifficulty,d,n,dp);
        return ans==INT_MAX?-1:ans;
    }
};