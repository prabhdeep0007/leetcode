class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string ,vector<string>> m;
        for(auto s:strs)
        {
            string temp=s;
            sort(s.begin(),s.end());
            m[s].push_back(temp);
        }
         vector<vector<string>> res;
        for(auto it:m)
        {
            res.push_back(it.second);
        }
        return res;
    }
    
};