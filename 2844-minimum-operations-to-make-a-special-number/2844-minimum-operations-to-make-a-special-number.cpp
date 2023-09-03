class Solution {
public:
    int solve(int i,int rem,string num,vector<vector<int>>&dp,int &n)
    {
        if(i==n)
        {
            if(rem%25==0) return 0;
                return 1e9;
        }
        if(dp[i][rem]!=-1) return dp[i][rem];
        int dig=num[i]-'0';
        int pick=solve(i+1,(rem*10+dig)%25,num,dp,n);
        int not_pick=1+solve(i+1,rem,num,dp,n);
        return dp[i][rem]=min(pick,not_pick);
    }
    int minimumOperations(string num) {
        int n=num.size();
     vector<vector<int>> dp(n,vector<int>(25,-1));
      return solve(0,0,num,dp,n);  
    }
};