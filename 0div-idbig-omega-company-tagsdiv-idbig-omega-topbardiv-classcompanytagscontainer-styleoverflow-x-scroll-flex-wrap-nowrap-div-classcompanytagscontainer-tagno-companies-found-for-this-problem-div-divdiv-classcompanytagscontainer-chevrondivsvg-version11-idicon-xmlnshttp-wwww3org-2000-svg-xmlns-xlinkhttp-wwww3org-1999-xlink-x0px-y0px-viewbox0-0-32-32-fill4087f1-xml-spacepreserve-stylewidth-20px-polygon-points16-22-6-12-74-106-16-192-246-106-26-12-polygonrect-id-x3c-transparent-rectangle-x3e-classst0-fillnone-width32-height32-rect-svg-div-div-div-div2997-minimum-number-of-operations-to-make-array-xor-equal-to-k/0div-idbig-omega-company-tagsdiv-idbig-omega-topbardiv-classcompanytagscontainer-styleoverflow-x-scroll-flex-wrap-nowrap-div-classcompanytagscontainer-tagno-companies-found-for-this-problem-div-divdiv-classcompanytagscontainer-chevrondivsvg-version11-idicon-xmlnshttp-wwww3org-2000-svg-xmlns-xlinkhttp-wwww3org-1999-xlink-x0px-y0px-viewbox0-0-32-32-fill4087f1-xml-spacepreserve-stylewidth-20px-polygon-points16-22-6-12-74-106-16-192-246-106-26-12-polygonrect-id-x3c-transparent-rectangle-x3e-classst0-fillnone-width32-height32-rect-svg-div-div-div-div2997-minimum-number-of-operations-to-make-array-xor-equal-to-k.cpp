class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=nums[0];
        for(int i=1;i<nums.size();i++){
            x^=nums[i];
        }
        int ans=0;
        while(k||x)
        {
            if((x&1) != (k&1)) ans++;
            x>>=1;
            k>>=1;
        }
        return ans;
        }
};