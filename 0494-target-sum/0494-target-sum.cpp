class Solution {
public:
    int solve(vector<int>& nums, int target,int i,int& n,map<pair<int,int>,int>&m)
    {
        if(i==n)
        {
            if(target==0) return 1;
            return 0;
        }
        if(m.find({i,target})!=m.end())return m[{i,target}];
        int pos=solve(nums,target-nums[i],i+1,n,m);
        int neg=solve(nums,target+nums[i],i+1,n,m);
       return  m[{i,target}]=pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
    map<pair<int,int>,int>m;
       return  solve(nums,target,0,n,m);
    }
};