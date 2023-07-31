class Solution {
public:
    int solve(string&s1,string&s2,int i,int j,vector<vector<int>>& dp)
    {
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans=s1[i]+solve(s1,s2,i-1,j-1,dp);
        }else{
            ans=max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));
        }
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size(),sum=0;
        for(int i=0;i<n;i++)
        {
         sum+=s1[i];   
        }
        for(int i=0;i<m;i++)
        {
         sum+=s2[i];   
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return sum-(2*solve(s1,s2,n-1,m-1,dp));
    }
};