class Solution {
public:
    int countOrders(int n) {
        int MOD=1e9+7;
        vector<long long> dp(n+1,0);
        dp[1]=1;
        if(n==1)
            return 1;
        dp[2]=6;
        for(int i=3;i<=n;i++){
            int t=2*i-1;
            dp[i]=t*(t+1)/2;
            dp[i]=(dp[i]*dp[i-1])%MOD;
            dp[i]=dp[i]%MOD;
        }
        return dp[n];
    }
};