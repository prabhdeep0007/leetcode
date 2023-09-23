class Solution {
public:
    static bool cmp(string &s1,string &s2)
    {
        return s2.size()>s1.size();
    }
    bool issubsequence(string &s,string &t)
    {
        int i=0,j=0;
        int n=s.size(),m=t.size();
        while(i<n && j<m)
        {
            if(s[i]==t[j]) 
            {
                i++; 
            }
            j++;
        }
    return i==n;
    }
    int solve(vector<string>& words,int i,int prev,vector<vector<int>> &dp)
     {
        if(i==words.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0;
            if(prev==-1 || issubsequence(words[prev],words[i]))
            {
                if(prev==-1 ||words[i].size()==words[prev].size()+1)
                    take=1+solve(words,i+1,i,dp);   
            }
        int nottake=solve(words,i+1,prev,dp);
        return dp[i][prev+1]=max(take,nottake);
     }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        vector<vector<int>> dp(words.size(),vector<int>(words.size()+1,-1));
        return solve(words,0,-1,dp);
    }
};