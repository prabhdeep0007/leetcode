class Solution {
public:
    void dfs(vector<vector<int>> &land,vector<vector<int>> &vis,int i,int j,int&r,int&c)
    {
        if(i==land.size()||j==land[0].size() ||vis[i][j] ||land[i][j]!=1) return;
        vis[i][j]=1;
        r=max(i,r);
        c=max(c,j);
        dfs(land,vis,i+1,j,r,c);
        dfs(land,vis,i,j+1,r,c);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(),m=land[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans;
        int r,c;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j]==1&&!vis[i][j])
                {
                    r=0,c=0;
                     dfs(land,vis,i,j,r,c);
                    ans.push_back({i,j,r,c});
                }
            }
        }
        return ans;
    }
};