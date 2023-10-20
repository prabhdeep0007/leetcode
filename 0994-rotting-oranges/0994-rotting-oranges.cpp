class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q; 
        int ans=0,count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                {
                  q.push({{i,j},0});
                    vis[i][j]=1;
                }
                if(grid[i][j]==1) count++;
            }
        }
        vector<int> x={0,0,1,-1};
        vector<int> y={1,-1,0,0};
        while(q.size())
        {
            auto node=q.front();
            q.pop();
            ans=max(node.second,ans);
            for(int i=0;i<4;i++)
            {
                int nx=node.first.first+x[i];
                int ny=node.first.second+y[i];
                if(nx>=0 && ny>=0 && nx<n &&ny<m &&!vis[nx][ny] &&grid[nx][ny]==1)
                {
                    vis[nx][ny]=1;
                    q.push({{nx,ny},node.second+1});
                    count--;
                }
            }
        }
        cout<<ans<<" "<<count<<endl;
        return count==0?ans:-1;
    }
};