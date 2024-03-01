class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int onecnt=count(s.begin(),s.end(),'1');
        int n=s.size();
        string ans="";
        while(n>1)
        {
            if(onecnt>1) 
            {
                ans+='1';
                onecnt--;
            }
            else ans+='0';
            n--;
        }
        ans+='1';
        return ans;
    }
};