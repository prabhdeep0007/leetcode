class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp=heights;
        sort(heights.begin(),heights.end());
        int ans=0;
        for(int i=0;i<heights.size();i++)
        {
         ans+=heights[i]==temp[i]?0:1;   
        }
        return ans;
    }
};