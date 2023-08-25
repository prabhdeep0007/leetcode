class Solution {
public:
    int solve(string& word1,string& word2,int i,int j, vector<vector<int>>&dp)
    {
       
        if(j<0)
        {
            return i+1;
        }   
        if(i<0)
        {
            return j+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int a=INT_MAX;
        if(word1[i]==word2[j])a=solve(word1,word2,i-1,j-1,dp);
       int b=1+solve(word1,word2,i-1,j,dp);
       int c=1+solve(word1,word2,i-1,j-1,dp);
       int d=1+solve(word1,word2,i,j-1,dp);
        return dp[i][j]=min(a,min(b,min(c,d)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(word1,word2,n-1,m-1,dp);
    }
};