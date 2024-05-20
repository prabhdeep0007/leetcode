class Solution {
public:
    int ans=0;
    void sum(vector<int>& nums,int i,int& count)
    {
        if(i==nums.size())
        {
            ans+=count;
            return;
        }
        count^=nums[i];
        sum(nums,i+1,count);
        count^=nums[i];
        sum(nums,i+1,count);
        
    }
    int subsetXORSum(vector<int>& nums) {
        int count=0;
        sum(nums,0,count);
        return ans;
    }
};