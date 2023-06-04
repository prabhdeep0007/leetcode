class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i+1;j++)
            {
             if(i==0 && j==0) 
             {
                 dp[i][j]=triangle[i][j];
                 cout<<dp[i][j]<<"  ";
             }
             else    
                {
                 int up=INT_MAX,rightup=INT_MAX;
                  if(i>0 && j!=i) up=triangle[i][j]+dp[i-1][j];
                  if(i>0 &&j>0) rightup=triangle[i][j]+dp[i-1][j-1];  
                 dp[i][j]=min(up,rightup);
                 cout<<dp[i][j]<<"  ";
                }
                
            }
            cout<<endl;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(dp[n-1][i],mini);
        }
        return mini;
    }
};