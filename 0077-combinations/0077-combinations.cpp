class Solution {
public:
    void solve(int i,int& n,int k,vector<vector<int>>& ans,vector<int>& temp)
    {
        if(k==0)
        {
        ans.push_back(temp);
            return;
        }
        if(i>n) return;
        solve(i+1,n,k,ans,temp);
        temp.push_back(i);
        solve(i+1,n,k-1,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,n,k,ans,temp);
        return ans;
    }
};