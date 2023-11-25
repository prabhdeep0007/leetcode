class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n,0),suff(n,0),ans;
        pre[0]=0;
        suff[n-1]=0;
        for(int i=1;i<n;i++)
        {
            pre[i]=nums[i-1]+pre[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
             suff[i]=suff[i+1]+nums[i+1];   
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back(abs(pre[i]-i*nums[i])+abs((n-i-1)*nums[i]-suff[i]));
        }
        return ans;
    }
};