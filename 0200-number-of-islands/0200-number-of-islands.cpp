class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j, vector<vector<int>>& vis,int &n,int&m)
    {
                    
           if(j-1>=0 && grid[i][j-1]=='1'&& !vis[i][j-1]) 
           {
               vis[i][j-1] =1;
               dfs(grid,i,j-1,vis,n,m);
           }
                  
           if(j+1<m && grid[i][j+1]=='1'&& !vis[i][j+1]) 
           {
               vis[i][j+1] =1;
               dfs(grid,i,j+1,vis,n,m);
           }
                  
           if(i-1>=0 && grid[i-1][j]=='1'&& !vis[i-1][j]) 
           {
               vis[i-1][j] =1;
               dfs(grid,i-1,j,vis,n,m);
           }
                  
           if(i+1<n  && grid[i+1][j]=='1'&& !vis[i+1][j]) 
           {
               vis[i+1][j] =1;
               dfs(grid,i+1,j,vis,n,m);
           }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int numberofislands=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] &&grid[i][j]=='1')
                {
                    numberofislands++;
                    vis[i][j]=1;
                    dfs(grid,i,j,vis,n,m);
                }
            }
        }
        return numberofislands;
    }
};