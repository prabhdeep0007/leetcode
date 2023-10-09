class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0) return {-1,-1};
        auto lowerB = lower_bound(nums.begin(),nums.end(),target);
        auto upperB = upper_bound(nums.begin(),nums.end(),target);
       if(lowerB == nums.end() || *lowerB != target)    return {-1,-1};
        int first= lowerB-nums.begin();
        int last= upperB-nums.begin()-1;
        return {first,last};
    }
};