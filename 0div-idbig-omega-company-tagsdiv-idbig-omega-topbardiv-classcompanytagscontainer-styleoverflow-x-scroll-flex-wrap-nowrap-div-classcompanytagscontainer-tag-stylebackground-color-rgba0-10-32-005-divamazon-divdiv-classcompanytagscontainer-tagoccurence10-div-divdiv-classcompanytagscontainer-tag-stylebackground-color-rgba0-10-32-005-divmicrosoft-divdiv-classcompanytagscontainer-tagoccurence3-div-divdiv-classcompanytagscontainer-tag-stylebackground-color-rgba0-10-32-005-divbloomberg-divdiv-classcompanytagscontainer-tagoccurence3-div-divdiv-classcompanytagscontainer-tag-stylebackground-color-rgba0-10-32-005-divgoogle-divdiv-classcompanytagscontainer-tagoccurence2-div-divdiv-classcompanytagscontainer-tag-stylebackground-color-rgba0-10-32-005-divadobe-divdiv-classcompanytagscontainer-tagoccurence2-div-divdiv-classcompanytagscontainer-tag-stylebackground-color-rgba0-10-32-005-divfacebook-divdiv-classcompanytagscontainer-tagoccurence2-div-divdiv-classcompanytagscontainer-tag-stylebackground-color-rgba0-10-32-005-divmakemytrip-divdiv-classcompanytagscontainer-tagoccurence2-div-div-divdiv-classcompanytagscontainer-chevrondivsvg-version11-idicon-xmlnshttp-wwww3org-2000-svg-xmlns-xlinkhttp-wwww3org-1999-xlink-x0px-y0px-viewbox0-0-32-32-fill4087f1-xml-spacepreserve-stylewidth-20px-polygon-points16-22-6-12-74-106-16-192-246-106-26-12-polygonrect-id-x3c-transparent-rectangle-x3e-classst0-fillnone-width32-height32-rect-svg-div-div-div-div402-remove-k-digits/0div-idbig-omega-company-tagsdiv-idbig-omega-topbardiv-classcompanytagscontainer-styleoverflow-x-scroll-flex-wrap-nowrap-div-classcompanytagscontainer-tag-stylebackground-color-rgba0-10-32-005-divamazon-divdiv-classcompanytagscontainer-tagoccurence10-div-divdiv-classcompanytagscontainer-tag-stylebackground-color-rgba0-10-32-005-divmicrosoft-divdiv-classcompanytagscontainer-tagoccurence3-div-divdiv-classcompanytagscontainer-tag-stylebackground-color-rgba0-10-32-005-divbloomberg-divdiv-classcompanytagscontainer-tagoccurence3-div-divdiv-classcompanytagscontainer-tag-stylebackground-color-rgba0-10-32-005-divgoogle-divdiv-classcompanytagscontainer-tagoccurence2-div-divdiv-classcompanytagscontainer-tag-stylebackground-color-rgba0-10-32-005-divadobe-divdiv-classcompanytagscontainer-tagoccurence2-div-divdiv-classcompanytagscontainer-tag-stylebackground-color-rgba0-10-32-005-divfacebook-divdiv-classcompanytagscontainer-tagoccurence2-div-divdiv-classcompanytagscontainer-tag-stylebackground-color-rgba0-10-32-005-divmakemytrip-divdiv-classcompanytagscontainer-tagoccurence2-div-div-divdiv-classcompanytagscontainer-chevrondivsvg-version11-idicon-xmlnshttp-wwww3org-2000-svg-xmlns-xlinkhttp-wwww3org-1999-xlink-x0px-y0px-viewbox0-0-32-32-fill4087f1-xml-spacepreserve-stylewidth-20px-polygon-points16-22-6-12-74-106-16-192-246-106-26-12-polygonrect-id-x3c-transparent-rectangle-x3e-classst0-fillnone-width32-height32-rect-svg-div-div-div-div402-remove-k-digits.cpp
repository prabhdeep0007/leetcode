class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(int i=0;i<num.size();i++)
        {
            while(ans.size()&& ans.back()>num[i]&&k)
            {
                ans.pop_back();
                k--;
            }
            if(ans.size()|| num[i]!='0')ans.push_back(num[i]);
        }
        while(ans.size()&&k)
        {
            ans.pop_back();
            k--;
        }
        return ans==""?"0":ans;
    }
};