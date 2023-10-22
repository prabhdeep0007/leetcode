class Solution {
public:
    void dfs(vector<vector<int>> &vis,int i,int j,int &n,int&m,vector<vector<char>>& board)
    {
       vector<int> x={0,0,1,-1};
       vector<int> y={1,-1,0,0};
        for(int k=0;k<4;k++)
        {
         int nx=i+x[k];
         int ny=j+y[k];
            if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && board[nx][ny]=='O')
            {
                vis[nx][ny]=1;
                dfs(vis,nx,ny,n,m,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
            vis[i][0]=1;
            dfs(vis,i,0,n,m,board); 
            }
            if(board[i][m-1]=='O')
            {
                vis[i][m-1]=1;
                dfs(vis,i,m-1,n,m,board);
            }
        }
         for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O')
            {
            vis[0][i]=1;
            dfs(vis,0,i,n,m,board); 
            }
            if(board[n-1][i]=='O')
            {
                vis[n-1][i]=1;
                dfs(vis,n-1,i,n,m,board);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};