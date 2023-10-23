class Solution {
public:
    vector<int> x={1,-1,0,0};
    vector<int> y={0,0,1,-1};
    void dfs(int i,int j,int &n,int&m,vector<vector<int>> & vis,vector<vector<int>> &grid)
    {
     for(int k=0;k<4;k++)
     {
         int nx=i+x[k];
         int ny=j+y[k];
         if(nx>=0 &&ny>=0 &&nx<n && ny<m && !vis[nx][ny] && grid[nx][ny])
         {
             vis[nx][ny]=1;
             dfs(nx,ny,n,m,vis,grid);
         }
         
     }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]) 
            {
                vis[i][0]=1;
                dfs(i,0,n,m,vis,grid);
            }
            if(grid[i][m-1])
            {
                vis[i][m-1]=1;
                dfs(i,m-1,n,m,vis,grid);
            }
        }
        for(int i=0;i<m;i++)
        {
          if(grid[0][i]) 
          {
              vis[0][i]=1;
              dfs(0,i,n,m,vis,grid);
          }
          if(grid[n-1][i])
          {
              vis[n-1][i]=1;
              dfs(n-1,i,n,m,vis,grid); 
          }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]&&!vis[i][j]) count++;
            }
        }
        return count;
    }
};