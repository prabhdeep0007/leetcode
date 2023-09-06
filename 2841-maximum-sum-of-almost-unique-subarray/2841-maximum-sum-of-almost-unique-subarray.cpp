class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        long long sum=0;
        for(int i=0;i<k;i++)
        {
            mp[nums[i]]++;
            sum+=nums[i];
        }
        int l=0,r=k-1;
         if(mp.size()>=m) ans=max(sum,ans);
        while(r<n-1)
        {
            sum-=nums[l];
            mp[nums[l]]--;
            if(mp[nums[l]]==0) mp.erase(nums[l]);
            l++;
            r++;
            sum+=nums[r];
            mp[nums[r]]++;
         if(mp.size()>=m) ans=max(sum,ans);
        }
        return ans;
    }
};