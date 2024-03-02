class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int i=0,m=nums.size();
        while(i<m&&nums[i]<0)
        {
            i++;
        }
        int j=i-1;
        while(j>=0&&i<m)
        {
            int a=nums[j]*nums[j],b=nums[i]*nums[i];
            if(a>b) 
            {
                ans.push_back(b);
                i++;
            }
            else 
            {
                ans.push_back(a);
                j--;
            }
        }
        while(j>=0)
        {
            ans.push_back(nums[j]*nums[j]);
            j--;
        }
        while(i<m)
        {
            ans.push_back(nums[i]*nums[i]);
            i++;
        }
        return ans;
    }
};