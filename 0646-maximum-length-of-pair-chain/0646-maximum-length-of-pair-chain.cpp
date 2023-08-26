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
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            int count=1;
            int ti=i;
            int j=i+1;
            while(j<n)
            {
                if(pairs[i][1]<pairs[j][0])
                {
                    count++;
                    i=j;
                }
                j++;
            }
            maxi=max(count,maxi);
        }
        return maxi;
    }
};