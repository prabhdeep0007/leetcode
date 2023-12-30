class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> m;
        int n=words.size();
        for(auto i:words)
        {
            for(auto c:i)
            {
                m[c]++;
            }
        }
        for(auto i:m)
        {
            if(i.second%n!=0) return 0;
        }
        return 1;
    }
};