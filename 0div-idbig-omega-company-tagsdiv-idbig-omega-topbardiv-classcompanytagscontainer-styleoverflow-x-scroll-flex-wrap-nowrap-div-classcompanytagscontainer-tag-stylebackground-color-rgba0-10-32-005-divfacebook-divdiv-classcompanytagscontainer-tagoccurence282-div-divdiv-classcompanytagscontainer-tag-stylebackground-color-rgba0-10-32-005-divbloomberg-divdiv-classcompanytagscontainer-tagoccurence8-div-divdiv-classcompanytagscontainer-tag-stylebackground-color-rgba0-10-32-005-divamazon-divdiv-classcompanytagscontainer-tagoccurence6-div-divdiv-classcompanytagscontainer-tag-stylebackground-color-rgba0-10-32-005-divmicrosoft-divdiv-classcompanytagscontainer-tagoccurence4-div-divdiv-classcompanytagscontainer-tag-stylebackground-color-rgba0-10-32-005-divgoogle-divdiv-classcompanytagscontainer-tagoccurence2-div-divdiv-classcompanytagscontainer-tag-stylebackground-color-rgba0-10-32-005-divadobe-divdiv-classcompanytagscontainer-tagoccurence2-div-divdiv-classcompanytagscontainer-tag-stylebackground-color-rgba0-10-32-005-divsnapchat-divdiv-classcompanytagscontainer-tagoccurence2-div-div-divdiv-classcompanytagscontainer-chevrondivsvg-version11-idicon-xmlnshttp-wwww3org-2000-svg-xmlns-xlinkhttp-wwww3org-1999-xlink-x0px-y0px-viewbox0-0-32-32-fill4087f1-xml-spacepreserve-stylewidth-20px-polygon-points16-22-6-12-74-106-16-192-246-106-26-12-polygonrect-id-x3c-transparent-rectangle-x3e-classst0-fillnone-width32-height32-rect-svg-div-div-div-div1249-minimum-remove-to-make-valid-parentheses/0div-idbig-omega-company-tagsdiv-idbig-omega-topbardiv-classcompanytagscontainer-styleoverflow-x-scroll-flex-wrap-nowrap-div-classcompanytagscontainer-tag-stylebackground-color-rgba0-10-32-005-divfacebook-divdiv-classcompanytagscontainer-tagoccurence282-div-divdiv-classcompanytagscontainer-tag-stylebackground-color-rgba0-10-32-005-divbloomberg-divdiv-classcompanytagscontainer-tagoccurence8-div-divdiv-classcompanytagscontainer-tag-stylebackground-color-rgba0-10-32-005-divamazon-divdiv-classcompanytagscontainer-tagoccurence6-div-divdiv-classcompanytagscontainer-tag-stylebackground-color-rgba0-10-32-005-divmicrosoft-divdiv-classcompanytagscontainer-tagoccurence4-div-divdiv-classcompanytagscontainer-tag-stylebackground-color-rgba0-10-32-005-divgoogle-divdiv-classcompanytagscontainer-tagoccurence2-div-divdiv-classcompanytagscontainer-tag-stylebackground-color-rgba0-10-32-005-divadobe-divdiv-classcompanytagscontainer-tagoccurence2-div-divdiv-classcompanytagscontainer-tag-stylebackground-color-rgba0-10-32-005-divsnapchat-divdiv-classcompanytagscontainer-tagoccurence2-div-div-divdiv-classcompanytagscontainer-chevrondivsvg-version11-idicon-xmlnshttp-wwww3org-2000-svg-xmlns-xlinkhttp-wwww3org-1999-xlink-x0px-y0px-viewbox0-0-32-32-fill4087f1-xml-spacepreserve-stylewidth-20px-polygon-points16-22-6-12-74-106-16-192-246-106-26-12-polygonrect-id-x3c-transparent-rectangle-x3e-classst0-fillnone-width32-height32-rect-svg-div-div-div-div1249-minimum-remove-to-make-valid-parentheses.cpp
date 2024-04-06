class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string ans="";

        int c=count(s.begin(),s.end(),')');
        int o=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                if(!st.empty())
                {
                    st.pop();
                    ans+=s[i];
                    o--;
                }
                  c--;
            }
            else if(s[i]=='(')
            {
                if(c>=o+1)
                {
                ans+=s[i];
                st.push('(');
                }
                o++;
            }
            else ans+=s[i];
        }
        return ans;
    }
};