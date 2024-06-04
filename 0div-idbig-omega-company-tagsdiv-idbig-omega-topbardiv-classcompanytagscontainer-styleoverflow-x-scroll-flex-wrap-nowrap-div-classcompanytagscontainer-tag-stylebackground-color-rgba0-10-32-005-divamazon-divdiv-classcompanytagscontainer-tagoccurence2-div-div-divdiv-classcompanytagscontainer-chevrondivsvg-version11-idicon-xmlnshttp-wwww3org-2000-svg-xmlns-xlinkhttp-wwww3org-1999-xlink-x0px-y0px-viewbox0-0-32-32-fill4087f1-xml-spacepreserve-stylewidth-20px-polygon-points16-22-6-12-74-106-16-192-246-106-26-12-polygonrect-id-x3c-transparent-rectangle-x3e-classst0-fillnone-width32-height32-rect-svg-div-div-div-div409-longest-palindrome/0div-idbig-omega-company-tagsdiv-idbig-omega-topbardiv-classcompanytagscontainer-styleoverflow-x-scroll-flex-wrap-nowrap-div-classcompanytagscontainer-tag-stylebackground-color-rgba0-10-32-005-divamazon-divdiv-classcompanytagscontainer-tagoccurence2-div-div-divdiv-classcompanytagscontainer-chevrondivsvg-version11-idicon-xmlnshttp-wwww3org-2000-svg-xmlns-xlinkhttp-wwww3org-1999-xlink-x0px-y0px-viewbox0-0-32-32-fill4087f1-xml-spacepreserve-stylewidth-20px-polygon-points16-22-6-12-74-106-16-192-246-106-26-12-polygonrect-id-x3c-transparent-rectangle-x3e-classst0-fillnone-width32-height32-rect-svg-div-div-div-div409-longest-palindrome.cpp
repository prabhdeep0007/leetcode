class Solution {
public: 
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        int n=s.size(),count=0;
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        for(auto &[a,b]:m)
        {
            if(b==1 || b%2) count++;
        }

        return count==0?n:n-count+1;
    }
};