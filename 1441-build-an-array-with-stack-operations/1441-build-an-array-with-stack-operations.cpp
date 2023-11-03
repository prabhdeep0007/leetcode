class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int size=target.size();
        int i=0,j=1;
        while(i<size)
        {
            if(j==target[i])
            {
                ans.push_back("Push");
                i++;
            }
            else
            {
                 ans.push_back("Push");
                 ans.push_back("Pop");
            }
            j++;
        }
        return ans;
    }
};