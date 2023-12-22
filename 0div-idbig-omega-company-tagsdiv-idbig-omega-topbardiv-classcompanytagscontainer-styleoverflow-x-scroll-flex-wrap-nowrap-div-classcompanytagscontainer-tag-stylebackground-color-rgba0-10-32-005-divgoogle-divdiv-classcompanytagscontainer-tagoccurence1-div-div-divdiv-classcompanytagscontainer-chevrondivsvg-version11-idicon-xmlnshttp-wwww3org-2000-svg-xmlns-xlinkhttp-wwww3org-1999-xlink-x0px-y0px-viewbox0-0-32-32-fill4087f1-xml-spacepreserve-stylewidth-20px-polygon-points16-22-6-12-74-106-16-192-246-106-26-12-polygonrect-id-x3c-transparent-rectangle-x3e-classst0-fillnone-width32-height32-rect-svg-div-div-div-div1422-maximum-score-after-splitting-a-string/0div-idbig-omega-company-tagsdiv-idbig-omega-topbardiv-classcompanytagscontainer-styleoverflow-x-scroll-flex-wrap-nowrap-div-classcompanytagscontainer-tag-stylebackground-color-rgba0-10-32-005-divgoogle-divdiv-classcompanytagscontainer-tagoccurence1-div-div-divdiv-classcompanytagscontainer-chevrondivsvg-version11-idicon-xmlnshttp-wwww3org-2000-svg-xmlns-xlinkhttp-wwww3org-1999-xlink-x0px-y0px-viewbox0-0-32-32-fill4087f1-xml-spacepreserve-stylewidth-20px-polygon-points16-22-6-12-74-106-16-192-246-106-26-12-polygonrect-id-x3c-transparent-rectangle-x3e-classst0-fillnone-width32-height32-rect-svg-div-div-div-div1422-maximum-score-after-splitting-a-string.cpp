class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int maxi=0;
        int nz=s[0]=='0';
        int no=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='1') no++;
        }
        maxi=max(no+nz,maxi);
        int j=1;
        while(j<n-1)
        {
            if(s[j]=='0') nz++;
            else no--;
            j++;
            maxi=max(no+nz,maxi); 
        }
        return maxi;
    }
};