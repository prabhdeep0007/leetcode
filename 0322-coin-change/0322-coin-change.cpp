class Solution {
public:
    int solve(vector<int>& coins, int amount,int ind, vector<vector<int>>&dp)
    {
        if(amount==0) return 0;
        if(ind==coins.size()|| amount<0) return 1e6;
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int mini=INT_MAX;
        int n=amount/coins[ind];
        for(int i=0;i<=n;i++)
        {
            int curr=i+solve(coins,amount-(i*coins[ind]),ind+1,dp);
            mini=min(curr,mini);
        }
        return dp[ind][amount]=mini;
    }
    int coinChange(vector<int>& coins, int amount) {
           int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int a=solve(coins,amount,0,dp);
        return a==1e6?-1:a;
    }
};