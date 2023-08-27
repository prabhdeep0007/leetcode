class Solution {
public:
    bool solve(int i,int k,vector<int>& stones,unordered_map<int,int>&m,int &n, vector<vector<int>>& dp)
    {
        if(i==n-1) return true;
        bool a=false,b=false,c=false;
        if(dp[i][k]!=-1) return dp[i][k];
        if(m[stones[i]+k])a=solve(m[stones[i]+k],k,stones,m,n,dp);
        if(m[stones[i]+k-1] && k-1>0)b=solve(m[stones[i]+k-1],k-1,stones,m,n,dp);
        if(m[stones[i]+k+1])c=solve(m[stones[i]+k+1],k+1,stones,m,n,dp);
        return dp[i][k]=a|b|c;
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> m;
        int n=stones.size();
          vector<vector<int>> dp(n,vector<int>(n+1,-1));
        for(int i=0;i<n;i++) m[stones[i]]=i;
        return solve(0,0,stones,m,n,dp);
    }
};