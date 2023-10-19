class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int &color,int &old,int& n,int& m,vector<vector<int>>&vis)
    {
        vector<int> x={0,0,1,-1},y={1,-1,0,0};
        for(int k=0;k<4;k++)
        {
            
            int nx=i+x[k];
            int ny=j+y[k];
           
            if(nx>=0 && nx<n && ny>=0 && ny<m&&!vis[nx][ny]&&image[nx][ny]==old)
            { 
             vis[nx][ny]=1;
             image[nx][ny]=color;
              dfs(image,nx,ny,color,old,n,m,vis);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
           int n=image.size(),m=image[0].size();
           vector<vector<int>> vis(n,vector<int>(m,0));
          int old=image[sr][sc];
           vis[sr][sc]=1;
           image[sr][sc]=color;
           dfs(image,sr,sc,color,old,n,m,vis);
        return image;
    }
};