class Solution {
public:

    int mincost(vector<int>& cost,int i,int &n,vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        mini=min(cost[i]+mincost(cost,i+1,n,dp),cost[i]+mincost(cost,i+2,n,dp));
        return dp[i]=mini;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(mincost(cost,0,n,dp),mincost(cost,1,n,dp));
    }
};