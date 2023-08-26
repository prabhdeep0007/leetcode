class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[1]<b[1]) return true;
        return false;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),cmp);
            int count=1;
            int i=0;
            int j=1;
            while(j<n)
            {
                if(pairs[i][1]<pairs[j][0])
                {
                    count++;
                    i=j;
                }
                j++;
            }        
        return count;
    }
};