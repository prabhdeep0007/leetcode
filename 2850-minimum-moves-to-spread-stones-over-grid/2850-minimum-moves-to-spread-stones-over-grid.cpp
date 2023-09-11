class Solution {
public:
 
    int minimumMoves(vector<vector<int>>& grid) {
        int cz=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0) cz++;
            }
        }
        if(cz==0) return 0;
        int ans=1000;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    for(int ni=0;ni<n;ni++)
                    {
                        for(int nj=0;nj<m;nj++)
                        {
                            if(grid[ni][nj]>1)
                            {
                                int d=abs(ni-i)+abs(nj-j);
                                grid[ni][nj]--;
                                grid[i][j]++;
                                ans=min(ans,d+minimumMoves(grid));
                                grid[ni][nj]++;
                                grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};