class Solution {
public:
    int solve(vector<int>& prices,int i,int &n,vector<int>& dp)
    {
        if(i>=n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=0;
        for(int j=i+1;j<n;j++)
        {
            if(prices[j]>prices[i])maxi=max(maxi,prices[j]-prices[i]+solve(prices,j+1,n,dp));
        }
        return dp[i]=max(maxi,solve(prices,i+1,n,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n,-1);
        return solve(prices,0,n,dp);
    }
};