class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> ans(n,vector<int>(m,0));
         vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                 vis[i][j]=1;
                 q.push({{i,j},0});
                }
            }
        }
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,1,-1};

        while(q.size())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int t=q.front().second;
            ans[i][j]=t;
            q.pop();
            for(int k=0;k<4;k++)
            {
                int nx=i+x[k];
                int ny=j+y[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&!vis[nx][ny])
                {
                   q.push({{nx,ny},t+1});
                    vis[nx][ny]=1;
                }
            }
        }
        
        return ans;
    }
};