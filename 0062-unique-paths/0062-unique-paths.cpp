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
        vector<int> curr(n,0);
        vector<int> next(n,0);
        for(int i=m-1;i>=0;i--){
            
            for(int j=n-1;j>=0;j--){
                if(i==m-1&&j==n-1)
                    curr[j]=1;
                else if(i==m-1)
                    curr[j]=curr[j+1];
                else if(j==n-1)
                    curr[j]=next[j];
                else curr[j]=next[j]+curr[j+1];
            }
            next=curr;
            
        }
        
        
        
        return curr[0];
    }
};