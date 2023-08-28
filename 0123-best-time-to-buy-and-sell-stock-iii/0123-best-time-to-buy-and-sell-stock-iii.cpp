class Solution {
public:
    int solve(vector<int>& prices,int i,int buy,int &n,vector<vector<vector<int>>>& dp,int count)
    {
        if(i==n ||count==0) return 0;
        int profit=0;
        if(dp[i][buy][count]!=-1) return dp[i][buy][count];
        if(buy)
        {
            profit=max(-prices[i]+solve(prices,i+1,0,n,dp,count),0+solve(prices,i+1,1,n,dp,count));
        }
        else profit=max(+prices[i]+solve(prices,i+1,1,n,dp,count-1),0+solve(prices,i+1,0,n,dp,count));
        return dp[i][buy][count]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,n,dp,2);
    }
};