class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int currsum=0;
        int maxlen=-1;
        for(auto i:nums) sum+=i;
        int l=0,r=0;
        while(r<nums.size())
        {
            currsum+=nums[r];
            
            while(l<=r && currsum>sum-x) 
            {
                currsum-=nums[l];
                l++;
            }
            if(currsum==sum-x) maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen==-1?-1:nums.size()-maxlen;
    }
};