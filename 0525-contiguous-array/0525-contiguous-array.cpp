class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
         sum+=nums[i]==0?-1:1;
        if(sum==0) ans=i+1;
        else if(m.find(sum)!=m.end())
         {
            ans=max(ans,i-m[sum]);
         }
        else m[sum]=i;
        }
        return ans;
    }
};