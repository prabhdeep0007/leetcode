class Solution {
public:
    int dp(int i,int j,int m,int n, vector<vector<int>> &t){
        
        if(i==m-1&&j==n-1){
            return 1;
        }
        if(i==m||j==n)
            return 0;
        if(t[i][j]!=-1)
            return t[i][j];
        return t[i][j]=dp(i+1,j,m,n,t)+dp(i,j+1,m,n,t);
        
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m,vector<int>(n,-1));
        return dp(0,0,m,n,t);
    }
};