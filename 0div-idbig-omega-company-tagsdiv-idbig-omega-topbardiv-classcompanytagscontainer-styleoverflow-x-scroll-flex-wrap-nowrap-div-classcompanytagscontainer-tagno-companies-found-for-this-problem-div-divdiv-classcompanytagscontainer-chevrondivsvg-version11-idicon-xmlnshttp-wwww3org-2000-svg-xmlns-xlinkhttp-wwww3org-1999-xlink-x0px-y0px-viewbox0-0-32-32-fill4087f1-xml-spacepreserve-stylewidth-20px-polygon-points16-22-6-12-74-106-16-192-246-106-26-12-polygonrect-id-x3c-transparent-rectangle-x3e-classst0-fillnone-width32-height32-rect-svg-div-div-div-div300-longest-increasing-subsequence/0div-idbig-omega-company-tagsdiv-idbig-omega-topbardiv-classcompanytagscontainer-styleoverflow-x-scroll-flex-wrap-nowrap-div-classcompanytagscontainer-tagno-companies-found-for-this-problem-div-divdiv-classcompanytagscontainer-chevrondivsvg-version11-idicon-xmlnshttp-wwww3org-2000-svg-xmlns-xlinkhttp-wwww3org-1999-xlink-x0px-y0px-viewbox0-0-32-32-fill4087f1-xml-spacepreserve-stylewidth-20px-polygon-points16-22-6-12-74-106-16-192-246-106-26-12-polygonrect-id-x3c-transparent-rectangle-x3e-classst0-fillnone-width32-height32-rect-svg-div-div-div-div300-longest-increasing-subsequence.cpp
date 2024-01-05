class Solution {
public:
    int solve(int i,vector<int>& nums,int prev,int &n,vector<vector<int>>&dp)
    {
        if(i==n) return 0;
        int maxi=0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        if(prev==-1||nums[i]>nums[prev])  maxi=1+solve(i+1,nums,i,n,dp);
        return dp[i][prev+1]=maxi=max(maxi,solve(i+1,nums,prev,n,dp));
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,nums,-1,n,dp);
    }
};