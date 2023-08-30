class Solution {
public:
    int solve(vector<int>& prices,int i,int buy,int k,int &n,vector<vector<vector<int>>>&dp)
    {
        if(k==0 || i==n) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        int profit=0;
        if(buy)
        {
            profit=max(-prices[i]+solve(prices,i+1,0,k,n,dp),solve(prices,i+1,1,k,n,dp));
        }
        else
        {
            profit=max(+prices[i]+solve(prices,i+1,1,k-1,n,dp),solve(prices,i+1,0,k,n,dp));
        }
        return dp[i][buy][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
       return solve(prices,0,1,k,n,dp);
    }
};