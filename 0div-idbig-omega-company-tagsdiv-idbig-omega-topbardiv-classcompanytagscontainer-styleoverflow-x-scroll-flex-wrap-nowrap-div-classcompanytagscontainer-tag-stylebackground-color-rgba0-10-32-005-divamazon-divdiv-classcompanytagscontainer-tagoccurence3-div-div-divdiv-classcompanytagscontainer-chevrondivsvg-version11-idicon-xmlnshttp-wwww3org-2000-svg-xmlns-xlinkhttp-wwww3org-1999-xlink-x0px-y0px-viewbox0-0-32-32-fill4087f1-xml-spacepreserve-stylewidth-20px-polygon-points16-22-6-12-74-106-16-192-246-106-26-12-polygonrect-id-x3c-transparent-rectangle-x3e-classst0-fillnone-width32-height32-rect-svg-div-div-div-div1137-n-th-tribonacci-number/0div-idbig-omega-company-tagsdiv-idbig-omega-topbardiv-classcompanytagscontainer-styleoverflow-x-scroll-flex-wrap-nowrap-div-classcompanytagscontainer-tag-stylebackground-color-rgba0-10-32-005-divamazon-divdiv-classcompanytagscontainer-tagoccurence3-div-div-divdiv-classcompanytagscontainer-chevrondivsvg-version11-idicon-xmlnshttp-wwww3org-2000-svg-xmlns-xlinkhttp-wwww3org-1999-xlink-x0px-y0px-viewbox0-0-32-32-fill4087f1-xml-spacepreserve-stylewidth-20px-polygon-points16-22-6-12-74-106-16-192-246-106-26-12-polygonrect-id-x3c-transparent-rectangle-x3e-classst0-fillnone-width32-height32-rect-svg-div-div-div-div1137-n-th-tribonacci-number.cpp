class Solution {
public:
    int solve( int i, vector<int>&dp)
    {
        if(i==0) return dp[i]= 0;
        if(i<=2) return dp[i]=1;
        if(dp[i]!=-1) return dp[i];
        dp[i]=solve(i-1,dp)+solve(i-2,dp)+solve(i-3,dp);
        return dp[i];
    }
    int tribonacci(int n) {
          vector<int> dp(n+1,-1);
         solve(n,dp);
          return dp[n];
    }
};