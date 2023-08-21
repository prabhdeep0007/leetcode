class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        string temp="";
        for(int i=0;i<n/2;i++)
        {
            temp+=s[i];
            string st="";
        for(int j=0;j<n/(i+1);j++)
        {
            st+=temp;
        }
            if(st==s) return true;    
        }
        return false;
        
    }
};