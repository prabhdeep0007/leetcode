class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans=0,n=nums.size();
        unordered_set<int> s;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
         if(nums[i]<=nums[i-1])
         {
             ans+=nums[i-1]+1-nums[i];
             nums[i]=nums[i-1]+1;
         }
        }
        return ans;
    }
};