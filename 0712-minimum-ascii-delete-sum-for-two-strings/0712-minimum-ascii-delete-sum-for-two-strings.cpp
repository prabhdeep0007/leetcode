class Solution {
public:
    int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i==s1.length() || j==s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            ans=s1[i]+solve(s1,s2,i+1,j+1,dp);
        }else{
            ans=max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
	int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        int sum=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            sum+=s1[i];
        }
        for(int i=0;i<m;i++){
            sum+=s2[i];
        }
        return sum-(2*(solve(s1,s2,0,0,dp)));
    }
};