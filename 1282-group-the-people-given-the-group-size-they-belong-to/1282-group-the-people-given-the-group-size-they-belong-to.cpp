class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> m;
        int n=group.size();
        for(int i=0;i<n;i++)
        {
            m[group[i]].push_back(i);
            if(m[group[i]].size()==group[i]) 
            {
                ans.push_back(m[group[i]]);
                 m[group[i]].clear();
            }
        }
        return ans;
    }
};