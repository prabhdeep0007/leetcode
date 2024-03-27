class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<2) return 0;
        int n=nums.size(),i=0,j=0,ans=0;
        int product=1;
        while(i<n&&j<n)
        {
            product*=nums[j];
            while(i<n&&product>=k)
             {
             product=product/nums[i];
             i++;
             }
           
           if(product<k) ans+=j-i+1;
               j++;
        }
       return ans;     
    }
};