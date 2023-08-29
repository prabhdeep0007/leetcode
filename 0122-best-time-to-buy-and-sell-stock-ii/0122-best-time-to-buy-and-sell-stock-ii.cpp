class Solution {
public:
    int solve(vector<int>& prices,int i,int &n,vector<vector<int>>& dp,int buy)
    {
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy)
        {
            profit=max(-prices[i]+solve(prices,i+1,n,dp,0),solve(prices,i+1,n,dp,1));
        }
        else
        {
            profit=max(prices[i]+solve(prices,i+1,n,dp,1),solve(prices,i+1,n,dp,0));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,n,dp,1);
    }
};