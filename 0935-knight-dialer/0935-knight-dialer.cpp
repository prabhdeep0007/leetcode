class Solution {
public:
    int MOD=1e9+7;
    int recurse(unordered_map<int,vector<int>> &m,int idx, int n,vector<vector<int>> &dp){
        if(n==0) return 1;
        if(dp[idx][n]!=-1) return dp[idx][n];
        int sum=0;
        for(int ele:m[idx]){
            sum=(sum+recurse(m,ele,n-1,dp))%MOD;
        }
        return dp[idx][n]=sum%MOD;
    }
    int knightDialer(int n) {
        unordered_map<int,vector<int>> m;
        m[1]={8,6};
        m[2]={7,9};
        m[3]={4,8};
        m[4]={3,9,0};
        m[6]={0,7,1};
        m[7]={2,6};
        m[8]={3,1};
        m[9]={2,4};
        m[0]={4,6};
        int ans=0;
        vector<vector<int>> dp(10,vector<int>(n+1,-1));
        for(int i=0;i<=9;i++){
            ans=(ans+recurse(m,i,n-1,dp))%MOD;
        }
        return ans%MOD;
    }
};