class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(nums[m]==target) return m;
            if(nums[l]<=nums[m])
            {
                if(nums[l]<=target && nums[m]>=target) h=m-1;
                else l=m+1;
            }
            else 
            {
                if(nums[h]>=target && nums[m]<=target) l=m+1;
                else h=m-1;
            }
        }
        return -1;
    }
};