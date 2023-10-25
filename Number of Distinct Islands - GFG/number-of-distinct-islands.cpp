//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   void dfs(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid,string & temp,int i0,int j0)
   {
     vector<int> x={0,0,1,-1};
     vector<int> y={1,-1,0,0};
     int a=i-i0;
     int b=j-j0;
     temp+=a;
     temp+=b;
     for(int k=0;k<4;k++)
     {
         int nx=i+x[k];
         int ny=j+y[k];
         if(nx>=0&&ny>=0&&nx<grid.size()&& ny<grid[0].size()&&grid[nx][ny] && !vis[nx][ny])
         {
             vis[nx][ny]=1;
             dfs(nx,ny,vis,grid,temp,i0,j0);
         }
     }
   }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        unordered_set<string> s;
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j])
                {
                    vis[i][j]=1;
                    string temp="";
                    dfs(i,j,vis,grid,temp,i,j);
                    s.insert(temp);
                }
            }
            
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends