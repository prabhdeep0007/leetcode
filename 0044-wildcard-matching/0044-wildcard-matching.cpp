class Solution {
public:
    bool solve(string& s, string &p,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0 && j<0) return true;
        if(j<0) return false;
        if(i<0)
        {  
            while(j>-1)
            {
                if(p[j]=='*') j--;
                else return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] ||p[j]=='?') return dp[i][j]= solve(s,p,i-1,j-1,dp);
        if(p[j]=='*')
        {
            bool a=solve(s,p,i-1,j,dp);
            bool b=solve(s,p,i-1,j-1,dp);
            bool c=solve(s,p,i,j-1,dp); 
            return dp[i][j]= a||b||c;
        }
         return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        return solve(s,p,s.size()-1,p.size()-1,dp);
    }
};