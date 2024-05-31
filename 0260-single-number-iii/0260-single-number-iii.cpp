class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(i<n-1&&nums[i]==nums[i+1])
            {
                i++;
            }else{
               ans.push_back(nums[i]); 
            }
            
        }
        return ans;
    }
};