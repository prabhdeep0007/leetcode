class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26,-1),ans;
        for(int i=0;i<s.size();i++)
        {
            last[s[i]-'a']=i;
        }
        int maxi=0,i=0;
        for(int j=0;j<s.size();j++)
        {
            maxi=max(maxi,last[s[j]-'a']);
             if(j==maxi) {
                ans.push_back(j-i+1);
                i=j+1;
            }
        }
        return ans;
        }
};