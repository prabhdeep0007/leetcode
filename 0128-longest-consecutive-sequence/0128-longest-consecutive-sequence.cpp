class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> m;
        for(auto i:nums)
        {
            if(!m[i])
            {
            m[i]=m[i-1]+m[i+1]+1;
            m[i-m[i-1]]=m[i];
            m[i+m[i+1]]=m[i];
            ans=max(m[i],ans);
            }
        }
        return ans;
    }
};