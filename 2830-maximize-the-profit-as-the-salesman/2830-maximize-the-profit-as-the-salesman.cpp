class Solution {
public:
    int solve(int idx,vector<vector<int>>& offers,vector<int>&dp)
    {
        if(idx==offers.size()) return 0;
        if(dp[idx]!=-1)return dp[idx];
        int nottake=solve(idx+1,offers,dp);
        int l=idx+1,h=offers.size()-1;
        int next=offers.size();
        while(l<=h)
        {
            int m=(l+h)/2;
            if(offers[m][0]>offers[idx][1])
            {
                h=m-1;
                next=m;
            }
            else
            {
                l=m+1;
            }
        }
        int take=offers[idx][2]+solve(next,offers,dp);
       return dp[idx]=max(take,nottake);
        
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        vector<int> dp(offers.size(),-1);
      return solve(0,offers,dp);
    }
};