class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
           int n=s.size();
        vector<int> diff(n,0);
        for(int i=0;i<n;i++)
        {
            diff[i]=abs(s[i]-t[i]);
        }
        int i=0,j=0,ans=0,cost=0;
        while(j<n)
        {
            cost+=diff[j];
            while(cost>maxCost)
            {
                cost-=diff[i];
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }

};