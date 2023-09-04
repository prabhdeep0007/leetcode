class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(),sum=0,ans=0;
        vector<int> count(k,0);
        count[0]++;
        for(auto i:nums)
        {
         sum+=i;
        if(count[(sum%k+k)%k])  ans+=count[(sum%k+k)%k];
         count[(sum%k+k)%k]++;
        }
        return ans;
    }
};