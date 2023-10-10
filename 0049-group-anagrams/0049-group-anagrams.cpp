class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> m;
        for(auto s:strs)
        {
            vector<int> temp(26,0);
            for(auto c:s)
            {
                temp[c-'a']++;
            }
            m[temp].push_back(s);
        }
         vector<vector<string>> res;
        for(auto it:m)
        {
            res.push_back(it.second);
        }
        return res;
    }
    
};