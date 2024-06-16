class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long maxi = 1, ans = 0, i = 0;
        int size = nums.size();
        
        while (maxi <= n) {
            if (i < size && nums[i] <= maxi) {
                maxi += nums[i];
                i++;
            } else {
                maxi += maxi;
                ans++;
            }
        }
        
        return ans;
    }
};