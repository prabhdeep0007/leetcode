class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=0 || nums[i]>n) 
            {
                nums[i]=n+1;
            }
        }
        for(auto i:nums)
        {
            if(abs(i)>n || nums[abs(i)-1]<0) continue;
            else nums[abs(i)-1]*=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) return i+1;
        }
        
        return n+1;
    }
};