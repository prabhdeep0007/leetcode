class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto &[i,pos]:m)
        {
            int maxi=INT_MIN;
            m[i].push_back(pos[0]+n);
            for(int i=1;i<pos.size();i++)
            {
              int seconds=(pos[i]-pos[i-1])/2;
             maxi=max(maxi,seconds);
            }
            ans=min(ans,maxi);
        }
        return ans;
    }
};