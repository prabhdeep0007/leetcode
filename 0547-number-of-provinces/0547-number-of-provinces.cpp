class Solution {
public:
    void dfs(vector<int> &vis,int node,vector<vector<int>>& isConnected,int &n)
    {
          for(int i=0;i<n;i++)
          {
              if(isConnected[node][i]==1&&!vis[i])
              {
                  vis[i]=1;
                  dfs(vis,i,isConnected,n);
              }
          }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                dfs(vis,i,isConnected,n);
                count++;
            }
        }
        return count;
    }
};