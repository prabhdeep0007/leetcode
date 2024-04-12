class Solution {
public:
    
    void solve(int col,vector<vector<string>> &ans,vector<string>&board,int n,vector<int> &lrow,vector<int>&updiagonal,vector<int>&lowdiagonal)
    {
        for(int row=0;row<n;row++)
        {
            if(col==n)
            {
                ans.push_back(board);
                return;
            }
            if(!lrow[row]&&!lowdiagonal[row+col]&&!updiagonal[n-1+col-row])
            {
                board[row][col]='Q';
                lrow[row]=1;
                lowdiagonal[row+col]=1;
                updiagonal[n-1+col-row]=1;
                solve(col+1,ans,board,n,lrow,updiagonal,lowdiagonal);
                board[row][col]='.';
                lrow[row]=0;
                lowdiagonal[row+col]=0;
                updiagonal[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n,s);
        vector<int> lrow(n,0),updiagonal(2*n-1,0),lowdiagonal(2*n-1,0);
        solve(0,ans,board,n,lrow,updiagonal,lowdiagonal);
        return ans;
    }
};