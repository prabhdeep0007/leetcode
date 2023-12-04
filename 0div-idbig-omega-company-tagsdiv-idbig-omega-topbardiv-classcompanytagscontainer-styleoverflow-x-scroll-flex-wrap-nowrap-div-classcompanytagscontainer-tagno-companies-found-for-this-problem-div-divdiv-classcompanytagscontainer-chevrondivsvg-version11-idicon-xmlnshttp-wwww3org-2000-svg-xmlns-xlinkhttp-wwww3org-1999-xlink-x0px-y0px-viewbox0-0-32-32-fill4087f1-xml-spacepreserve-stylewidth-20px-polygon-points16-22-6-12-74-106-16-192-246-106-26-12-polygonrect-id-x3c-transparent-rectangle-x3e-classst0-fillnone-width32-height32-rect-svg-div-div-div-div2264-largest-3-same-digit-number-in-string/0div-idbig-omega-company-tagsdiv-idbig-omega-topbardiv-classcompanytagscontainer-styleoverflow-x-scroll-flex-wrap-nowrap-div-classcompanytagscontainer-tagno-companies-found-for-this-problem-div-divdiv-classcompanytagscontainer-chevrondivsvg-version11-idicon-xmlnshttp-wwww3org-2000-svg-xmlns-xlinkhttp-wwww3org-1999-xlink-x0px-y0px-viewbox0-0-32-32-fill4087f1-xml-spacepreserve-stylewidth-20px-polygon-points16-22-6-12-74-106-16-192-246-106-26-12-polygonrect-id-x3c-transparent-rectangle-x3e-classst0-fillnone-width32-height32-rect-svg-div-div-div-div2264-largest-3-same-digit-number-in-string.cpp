class Solution {
public:
    
    string largestGoodInteger(string nums) {
        int ans=INT_MIN,n=nums.size();
        for(int i=2;i<n;i++)
        {
            if(nums[i]==nums[i-1] && nums[i]==nums[i-2])
            {
                ans=max(ans,nums[i]-'0');
            }
        }
        if(ans==INT_MIN) return "";
        string a="";
        a+=to_string(ans);
        a+=to_string(ans);
        a+=to_string(ans);
        return a;
    }
};