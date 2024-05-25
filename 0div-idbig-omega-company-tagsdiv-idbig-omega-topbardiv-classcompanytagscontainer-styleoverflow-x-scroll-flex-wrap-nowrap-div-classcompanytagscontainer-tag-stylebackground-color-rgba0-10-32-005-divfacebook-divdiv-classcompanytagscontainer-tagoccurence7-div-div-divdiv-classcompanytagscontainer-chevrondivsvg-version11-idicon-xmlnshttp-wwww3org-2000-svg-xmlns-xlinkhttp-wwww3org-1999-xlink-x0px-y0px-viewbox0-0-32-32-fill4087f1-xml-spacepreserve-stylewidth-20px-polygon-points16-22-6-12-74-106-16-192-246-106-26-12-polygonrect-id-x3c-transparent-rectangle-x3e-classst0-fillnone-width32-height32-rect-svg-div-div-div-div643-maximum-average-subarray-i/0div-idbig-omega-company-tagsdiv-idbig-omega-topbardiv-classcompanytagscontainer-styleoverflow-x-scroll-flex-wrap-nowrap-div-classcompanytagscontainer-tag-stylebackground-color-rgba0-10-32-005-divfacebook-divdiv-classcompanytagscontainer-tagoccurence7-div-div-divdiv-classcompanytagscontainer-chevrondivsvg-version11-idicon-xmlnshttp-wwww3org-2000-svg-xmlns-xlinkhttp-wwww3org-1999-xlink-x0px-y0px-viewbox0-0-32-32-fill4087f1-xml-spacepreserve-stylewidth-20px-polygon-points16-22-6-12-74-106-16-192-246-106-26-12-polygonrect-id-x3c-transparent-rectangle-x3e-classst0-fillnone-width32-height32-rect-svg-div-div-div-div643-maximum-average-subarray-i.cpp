class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        double ans=INT_MIN;
        sum=accumulate(nums.begin(),nums.begin()+k,0);
        ans=max((double)sum/k,ans);
        int j=0;
        for(int i=k;i<nums.size();i++)
        {
            sum-=nums[j];
            sum+=nums[i];
            ans=max((double)sum/k,ans);
            j++;
        }
        return ans;
    }
};