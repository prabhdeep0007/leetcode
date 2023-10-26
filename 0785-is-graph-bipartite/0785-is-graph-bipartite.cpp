class Solution {
public:
    bool solve(int i,vector<vector<int>>& graph,vector<int>& vis)
    {
        bool ans=true;
        for(auto j:graph[i])
        {
            if(vis[j]==-1)
            {
                 vis[j]=(vis[i]==1)?0:1;
                ans=ans&solve(j,graph,vis);
            }
            else
            {
                if(vis[i]==vis[j]) return false;
            }
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        bool ans=true;
        for(int i=0;i<n;i++)
        {
         if(vis[i]==-1) 
         {
             vis[i]=0;
             ans=ans&solve(i,graph,vis);
         }
        }
        return ans;
    }
};