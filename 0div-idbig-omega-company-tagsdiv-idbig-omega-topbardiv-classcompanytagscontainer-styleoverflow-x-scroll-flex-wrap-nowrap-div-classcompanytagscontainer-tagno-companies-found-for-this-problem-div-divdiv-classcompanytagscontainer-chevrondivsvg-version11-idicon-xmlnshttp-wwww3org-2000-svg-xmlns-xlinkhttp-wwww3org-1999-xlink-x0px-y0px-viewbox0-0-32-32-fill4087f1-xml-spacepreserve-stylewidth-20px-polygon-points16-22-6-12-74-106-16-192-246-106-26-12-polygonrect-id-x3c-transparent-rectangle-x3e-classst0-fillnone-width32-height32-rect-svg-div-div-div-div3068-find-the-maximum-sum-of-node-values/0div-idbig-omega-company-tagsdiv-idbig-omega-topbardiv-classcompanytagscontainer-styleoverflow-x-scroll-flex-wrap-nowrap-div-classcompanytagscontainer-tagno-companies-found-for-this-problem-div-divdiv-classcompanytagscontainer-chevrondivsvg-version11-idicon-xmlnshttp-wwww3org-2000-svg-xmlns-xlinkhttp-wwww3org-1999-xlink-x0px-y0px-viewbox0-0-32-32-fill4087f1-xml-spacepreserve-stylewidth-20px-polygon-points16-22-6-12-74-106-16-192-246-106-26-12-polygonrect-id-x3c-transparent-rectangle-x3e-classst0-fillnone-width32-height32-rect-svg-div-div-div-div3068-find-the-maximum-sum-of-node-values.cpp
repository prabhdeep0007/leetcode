class Solution {
public:
     long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
            long long sum = 0, count = 0, remove= INT_MAX;
            for (long long n:nums) {
                sum+=max(n ^ k, n);
                count+=(n ^ k) > n;
                remove=min(remove, abs(n-(n ^ k)));
            }
            return sum - (count % 2 ? remove : 0);
    }
};