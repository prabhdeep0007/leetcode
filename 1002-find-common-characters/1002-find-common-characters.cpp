class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> global(26,INT_MAX);
        for(auto s:words)
        {
         vector<int> temp(26,0);
        for(int i=0;i<s.size();i++){
            temp[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            global[i]=min(global[i],temp[i]);
        }
        }
        
        vector<string> ans;
        for(int i=0;i<26;i++)
        {
            while(global[i])
            {
                string t="";
                t+=('a'+i);
                ans.push_back(t);
                global[i]--;
            }
        }
        return ans;
        }
};