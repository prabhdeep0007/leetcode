class Solution {
public:
    int mod=1e9+7;
    long long solve(int ind,int& goal,int& k,vector<int>& vis,vector<vector<long long>>&dp,int& n)
    {
        if(ind==goal)
        {
            for(int i=0;i<n;i++)
             {
              if(vis[i]==-1) return 0;  
             }
            return 1;
        }
        int unique=0;
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i]!=-1) unique++;
        }
        if(dp[ind][unique]!=-1) return dp[ind][unique];
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]<ind)
            {
                int prev=vis[i];
                vis[i]=ind+k;
                ans=(ans+solve(ind+1,goal,k,vis,dp,n))%mod;
                vis[i]=prev;
            }
        }
        return dp[ind][unique]=ans;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<int> vis(n,-1);
        vector<vector<long long>>dp(101,vector<long long>(101,-1));
        return (int)solve(0,goal,k,vis,dp,n);
    }
};