class Solution {
public:
    void solve(int n,vector<int>&vis,vector<int> &temp,vector<vector<int>>& ans,vector<int>& nums)
    {
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                vis[i]=1;
                temp.push_back(nums[i]);
                solve(n,vis,temp,ans,nums);
                vis[i]=-1;
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int> temp,vis(n,-1);
        solve(n,vis,temp,ans,nums);
        return ans;
    }
};