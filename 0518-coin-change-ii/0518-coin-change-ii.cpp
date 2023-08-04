class Solution {
public:
    int solve(int amount, vector<int>& coins,int ind,int &n,vector<vector<int>> &dp)
    {
        if(amount==0) return 1;
        if(amount<0||ind==n) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int l=amount/coins[ind];
        int ans=0;
        for(int i=0;i<=l;i++)
        {
            ans+=solve(amount-(i*coins[ind]),coins,ind+1,n,dp);
        }
        return dp[ind][amount]=ans;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(amount,coins,0,n,dp);
    }
};