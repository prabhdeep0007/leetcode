class Solution {
public:
    bool isvalid(int i,string &s,int open, vector<vector<int>>&dp)
    {
        if(i==s.size())
        {
            if(open==0) return true;
            return false;
        }
        if(dp[i][open]!=-1) return dp[i][open];
        if(s[i]=='(')
        {
            return dp[i][open]=isvalid(i+1,s,open+1,dp);
        }
        else if(s[i]==')')
        {
            if(open==0) return dp[i][open]=false;
            else {
                return dp[i][open]=isvalid(i+1,s,open-1,dp);
            }
        }
        else
        {
            if(isvalid(i+1,s,open,dp)) return dp[i][open]= true;
            if(isvalid(i+1,s,open+1,dp))return dp[i][open]= true;
            if(open!=0) if(isvalid(i+1,s,open-1,dp)) return dp[i][open]=true;
            return dp[i][open]=false;
        }
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return isvalid(0,s,0,dp);
    }
};