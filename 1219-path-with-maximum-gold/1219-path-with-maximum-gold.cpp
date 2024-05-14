class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int&n,int&m)
    {
        if(i<0||j<0||i==n||j==m||grid[i][j]==0 ) return 0;
        int ans=0;
        int a=grid[i][j];
        grid[i][j]=0;
        ans=max(a+solve(grid,i+1,j,n,m),ans);
        ans=max(a+solve(grid,i-1,j,n,m),ans);
        ans=max(a+solve(grid,i,j+1,n,m),ans);
        ans=max(a+solve(grid,i,j-1,n,m),ans);
        grid[i][j]=a;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
            if(grid[i][j])
            {
                ans=max(ans,solve(grid,i,j,n,m));
            }
            }
        }
        return ans;
    }
};