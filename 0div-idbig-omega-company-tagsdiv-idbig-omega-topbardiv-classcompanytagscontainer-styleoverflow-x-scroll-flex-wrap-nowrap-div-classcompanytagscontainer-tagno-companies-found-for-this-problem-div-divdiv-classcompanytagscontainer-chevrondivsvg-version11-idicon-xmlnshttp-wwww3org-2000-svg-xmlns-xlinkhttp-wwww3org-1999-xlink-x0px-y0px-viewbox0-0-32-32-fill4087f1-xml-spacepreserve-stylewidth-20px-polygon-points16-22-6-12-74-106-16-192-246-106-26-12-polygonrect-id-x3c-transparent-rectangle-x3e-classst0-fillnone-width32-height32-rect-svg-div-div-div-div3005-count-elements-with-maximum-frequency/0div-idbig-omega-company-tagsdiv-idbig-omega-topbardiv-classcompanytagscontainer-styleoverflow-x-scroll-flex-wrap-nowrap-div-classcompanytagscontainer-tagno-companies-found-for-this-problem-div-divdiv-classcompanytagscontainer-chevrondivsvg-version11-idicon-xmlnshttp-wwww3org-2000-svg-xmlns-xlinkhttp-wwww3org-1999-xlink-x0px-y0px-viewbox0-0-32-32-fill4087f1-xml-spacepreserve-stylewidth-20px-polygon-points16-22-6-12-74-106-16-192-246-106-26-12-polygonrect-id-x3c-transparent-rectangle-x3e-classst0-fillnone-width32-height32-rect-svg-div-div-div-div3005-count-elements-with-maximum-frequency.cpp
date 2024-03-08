class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
       unordered_map<int,int> m;
       for(auto &i:nums) m[i]++;
        int maxi=-1;
        for(auto &[a,b]:m)
        {
           maxi=max(b,maxi);
        }
        int ans=0;
        for(auto &[a,b]:m)
        {
           if(b==maxi) ans+=b;
        }
        return ans;
    }
};