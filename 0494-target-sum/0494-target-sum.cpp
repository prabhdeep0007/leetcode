class Solution {
public:
    int solve(vector<int>& nums, int target,int i,int& n)
    {
        if(i==n)
        {
            if(target==0) return 1;
            return 0;
        }
        int pos=solve(nums,target-nums[i],i+1,n);
        int neg=solve(nums,target+nums[i],i+1,n);
        return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // vector<vector<int>> dp()
       return  solve(nums,target,0,n);
    }
};