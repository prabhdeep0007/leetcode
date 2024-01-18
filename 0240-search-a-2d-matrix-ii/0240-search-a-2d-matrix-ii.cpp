class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int i=0,j=nums[0].size()-1;
        int n=nums.size();
        while(i<n && j>=0)
        {
            if(nums[i][j]>target) j--;
            else if(nums[i][j]<target) i++;
            else return true;
        }
        return false;
    }
};