class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
       unordered_map<int,int> m;
        unordered_set<int> s;
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            s.insert(nums[i]);
        }
        while(m.size())
        {
            vector<int> temp;
            for(auto i:s)
            {
                if(m[i])
                {
                    temp.push_back(i);
                    m[i]--;
                }
                if(m[i]==0) m.erase(i);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};