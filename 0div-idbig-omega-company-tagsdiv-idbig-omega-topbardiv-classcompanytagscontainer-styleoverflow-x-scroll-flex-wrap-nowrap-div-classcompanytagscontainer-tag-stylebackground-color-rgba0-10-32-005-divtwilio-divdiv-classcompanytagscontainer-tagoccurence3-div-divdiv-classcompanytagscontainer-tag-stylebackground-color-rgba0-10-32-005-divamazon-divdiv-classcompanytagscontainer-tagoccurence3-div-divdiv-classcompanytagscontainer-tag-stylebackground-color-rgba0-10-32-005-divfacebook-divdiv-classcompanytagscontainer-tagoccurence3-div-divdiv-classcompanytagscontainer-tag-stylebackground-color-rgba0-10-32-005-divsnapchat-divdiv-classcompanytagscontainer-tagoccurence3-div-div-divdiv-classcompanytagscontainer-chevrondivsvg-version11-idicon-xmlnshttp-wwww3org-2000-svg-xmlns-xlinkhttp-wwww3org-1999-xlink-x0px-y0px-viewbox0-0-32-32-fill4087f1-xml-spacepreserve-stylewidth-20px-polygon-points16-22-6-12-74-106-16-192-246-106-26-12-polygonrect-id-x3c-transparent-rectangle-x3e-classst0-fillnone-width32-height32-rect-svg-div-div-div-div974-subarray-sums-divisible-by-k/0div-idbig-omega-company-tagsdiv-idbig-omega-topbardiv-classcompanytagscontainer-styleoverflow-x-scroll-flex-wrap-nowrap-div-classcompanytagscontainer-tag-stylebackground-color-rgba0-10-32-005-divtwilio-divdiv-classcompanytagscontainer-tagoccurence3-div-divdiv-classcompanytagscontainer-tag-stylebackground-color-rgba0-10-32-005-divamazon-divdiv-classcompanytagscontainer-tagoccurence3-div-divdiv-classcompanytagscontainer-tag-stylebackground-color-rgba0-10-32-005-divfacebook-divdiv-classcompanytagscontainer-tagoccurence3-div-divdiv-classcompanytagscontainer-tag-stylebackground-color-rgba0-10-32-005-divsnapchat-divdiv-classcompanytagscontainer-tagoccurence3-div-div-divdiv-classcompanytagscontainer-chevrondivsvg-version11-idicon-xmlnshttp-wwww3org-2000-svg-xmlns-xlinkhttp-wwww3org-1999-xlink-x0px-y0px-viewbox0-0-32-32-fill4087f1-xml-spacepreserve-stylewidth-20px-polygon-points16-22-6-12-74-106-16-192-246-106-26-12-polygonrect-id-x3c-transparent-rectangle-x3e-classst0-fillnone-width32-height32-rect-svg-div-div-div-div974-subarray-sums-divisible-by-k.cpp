class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        int sum=0,ans=0;
         m[0]=1;
        for(int i=0;i<nums.size();i++)
        {
        sum+=nums[i];
        if(m[(sum%k+k)%k])  ans+=m[(sum%k+k)%k];
         m[(sum%k+k)%k]++;
        }
        return ans;
    }
};