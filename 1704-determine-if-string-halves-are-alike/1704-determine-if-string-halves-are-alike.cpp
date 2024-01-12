class Solution {
public:
    bool isvowel(char c)
    {
        string s="aeiouAEIOU";
        if(s.find(c)==string::npos) return false;
        return true;
    }
    bool halvesAreAlike(string s) {
        int i,n=s.size(),c1=0,c2=0;
     for(i=0;i<n/2;i++) if(isvowel(s[i]))c1++;
     for(;i<n;i++) if(isvowel(s[i]))c2++;
        return c1==c2;
    }
};