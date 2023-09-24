class Solution {
public:
    double solve(int& poured, int row, int glass, vector<vector<double>>& dp)
    {
        if(row < 0 || glass > row || glass < 0)
        {
            return 0.00;
        }
        if(dp[row][glass]!=-1) return dp[row][glass]; 
        if(row == 0 && glass == 0)
        {
            return poured;
        }
         double left = (solve(poured, row - 1, glass - 1,dp) - 1) / 2;
        left=max(0.00,left);
        double right=(solve(poured, row - 1, glass,dp) - 1) / 2;
        right=max(0.00,right);
        double total=left+right;
        return dp[row][glass]=total;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double>(101,-1));
        double ans=solve(poured,query_row,query_glass,dp);
        return ans<=1?ans:1;
    }
};