class Solution {
public:
    int solve(vector<int>& jd, int d,int i,int &n,vector<vector<int>> &dp)
    {
        if(dp[i][d]!=-1) return dp[i][d];
        if(d==1)
        {
            int maxi=INT_MIN;
            for(int j=i;j<n;j++)
            {
                maxi=max(maxi,jd[j]);
            }
            return maxi;
        }
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int j=i;j<=n-d;j++)
        {
            maxi=max(maxi,jd[j]);
            mini=min(mini,maxi+solve(jd,d-1,j+1,n,dp));
        }
        return dp[i][d]=mini;
    }
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        if(d>n) return -1;   
        vector<vector<int>> dp(n,vector<int>(d+1,-1));
        return solve(jd,d,0,n,dp);
    }
};