class Solution {
public:
      int solve(vector<int>& prices,int i,int &n,vector<vector<int>>& dp,int buy,int &fee)
    {
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy)
        {
            profit=max(-prices[i]+solve(prices,i+1,n,dp,0,fee),solve(prices,i+1,n,dp,1,fee));
        }
        else
        {
            profit=max(prices[i]+solve(prices,i+1,n,dp,1,fee)-fee,solve(prices,i+1,n,dp,0,fee));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(prices,0,n,dp,1,fee);
    } 
};