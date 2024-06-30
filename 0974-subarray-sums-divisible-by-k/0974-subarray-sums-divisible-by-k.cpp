class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(m.find((sum%k+k)%k)!=m.end())
            {
                ans+=m[(sum%k+k)%k];
            }
            m[(sum%k+k)%k]++;
        }
        return ans;
    }
};