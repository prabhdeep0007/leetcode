class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(),l=0,m=0,h=n-1;
        while(m<=h)
        {
            if(nums[m]==1)
            {
                m++;
            }
            else if(nums[m]==2)
            {
                swap(nums[h],nums[m]);
                h--;
            }
            else 
            {
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
        }
    }
};