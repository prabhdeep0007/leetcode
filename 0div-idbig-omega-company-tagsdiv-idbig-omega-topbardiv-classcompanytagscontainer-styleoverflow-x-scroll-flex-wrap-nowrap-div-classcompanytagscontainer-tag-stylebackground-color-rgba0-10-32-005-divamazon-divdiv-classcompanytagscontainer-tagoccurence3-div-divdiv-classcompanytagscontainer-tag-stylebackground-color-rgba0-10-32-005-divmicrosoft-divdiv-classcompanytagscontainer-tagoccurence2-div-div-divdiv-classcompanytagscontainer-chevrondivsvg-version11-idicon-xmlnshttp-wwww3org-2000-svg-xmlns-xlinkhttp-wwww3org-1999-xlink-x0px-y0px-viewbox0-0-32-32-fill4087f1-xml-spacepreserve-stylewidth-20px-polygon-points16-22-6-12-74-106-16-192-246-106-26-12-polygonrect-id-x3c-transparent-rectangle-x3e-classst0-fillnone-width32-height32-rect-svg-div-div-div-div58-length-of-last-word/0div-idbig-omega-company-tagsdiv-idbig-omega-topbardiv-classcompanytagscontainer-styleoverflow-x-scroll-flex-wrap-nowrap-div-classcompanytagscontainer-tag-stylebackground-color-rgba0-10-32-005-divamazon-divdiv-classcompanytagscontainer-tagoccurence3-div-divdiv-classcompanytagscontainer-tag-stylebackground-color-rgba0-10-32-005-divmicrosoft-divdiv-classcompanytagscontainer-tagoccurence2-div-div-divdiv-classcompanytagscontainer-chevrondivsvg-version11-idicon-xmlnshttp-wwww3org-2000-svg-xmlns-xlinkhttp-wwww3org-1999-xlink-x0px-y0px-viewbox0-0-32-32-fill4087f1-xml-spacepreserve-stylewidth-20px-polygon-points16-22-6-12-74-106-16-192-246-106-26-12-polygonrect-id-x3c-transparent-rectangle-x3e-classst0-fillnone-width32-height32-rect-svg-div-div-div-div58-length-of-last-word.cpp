class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        int ans;
        while(ss>>word)
        {
            ans=word.size();
        }
        return ans;
    }
};