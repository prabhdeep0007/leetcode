class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]=1;
        int s=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            if(m[s-k]) ans+=m[s-k];
            m[s]++;
        }
        return ans;
    }
};