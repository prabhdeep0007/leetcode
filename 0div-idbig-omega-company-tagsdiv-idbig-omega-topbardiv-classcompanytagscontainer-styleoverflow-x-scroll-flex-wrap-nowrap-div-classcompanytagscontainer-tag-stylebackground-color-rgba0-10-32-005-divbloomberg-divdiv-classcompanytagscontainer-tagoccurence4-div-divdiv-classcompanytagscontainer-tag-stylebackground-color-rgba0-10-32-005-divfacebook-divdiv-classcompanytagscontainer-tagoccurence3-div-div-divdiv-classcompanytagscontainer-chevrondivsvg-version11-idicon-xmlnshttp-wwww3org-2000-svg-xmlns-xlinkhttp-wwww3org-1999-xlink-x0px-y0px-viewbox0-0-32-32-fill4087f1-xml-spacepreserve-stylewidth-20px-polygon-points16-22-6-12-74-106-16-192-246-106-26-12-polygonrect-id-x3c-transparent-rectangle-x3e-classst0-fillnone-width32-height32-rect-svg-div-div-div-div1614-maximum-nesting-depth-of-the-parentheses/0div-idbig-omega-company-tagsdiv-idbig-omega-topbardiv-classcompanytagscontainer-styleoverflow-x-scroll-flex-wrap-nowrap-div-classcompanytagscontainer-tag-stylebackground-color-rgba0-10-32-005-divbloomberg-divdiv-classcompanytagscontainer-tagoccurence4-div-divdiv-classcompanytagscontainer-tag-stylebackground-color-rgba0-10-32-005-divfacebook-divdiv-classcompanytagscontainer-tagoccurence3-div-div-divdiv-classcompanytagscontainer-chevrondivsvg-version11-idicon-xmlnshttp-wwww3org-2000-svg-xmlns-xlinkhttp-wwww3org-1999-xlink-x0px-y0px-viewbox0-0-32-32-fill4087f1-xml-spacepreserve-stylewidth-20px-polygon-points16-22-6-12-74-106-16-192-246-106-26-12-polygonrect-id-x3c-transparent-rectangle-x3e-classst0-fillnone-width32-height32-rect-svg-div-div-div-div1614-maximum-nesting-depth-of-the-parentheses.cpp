class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(1);
                ans=max((int)st.size(),ans);
            }
            else if(s[i]==')') st.pop();
            
        }
        return ans;
    }
};