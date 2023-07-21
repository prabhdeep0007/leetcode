class Solution {
public:
    pair<int,int> solve(int i,int prev,vector<int>& nums,vector<vector<pair<int,int>>>&dp,int &n)
    {
        if(i==n) return{0,1};
        if(dp[i][prev+1].second!=-1) return dp[i][prev+1];
        int length=0,count=0;
        if(prev==-1 || nums[i]>nums[prev])
        {
            pair<int,int> take=solve(i+1,i,nums,dp,n);
            length=take.first+1;
            count=take.second;
        }
        pair<int,int> donttake=solve(i+1,prev,nums,dp,n);
        if(donttake.first>length)
        {
            length=donttake.first;
            count=donttake.second;
        }else if(donttake.first==length)
        {
            count+=donttake.second;
        }
        return dp[i][prev+1]={length,count};
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n+1,{-1,-1}));
        return solve(0,-1,nums,dp,n).second;  
    }
};