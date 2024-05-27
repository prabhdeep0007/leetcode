class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=0,n=nums.size();
        for(int i=0;i<=n;i++)
        {
            while(j<n&&nums[j]<i)
            {
                j++;
            }
            if(n-j==i) return i;
            // else if(n-j<i) break;
        }
    
        return -1;
    }
};