class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
      vector<int> v(n+1,0);
        for(int i=0;i<=n;i++)
        {
            int l=(i-ranges[i]<0)?0:i-ranges[i];
            int r=(i+ranges[i]>n)?n:i+ranges[i];
            v[l]=max(r,v[l]);
        }
        int maxend=0,taps=0,currend=0;
        
        for(int i=0;i<=n;i++)
        {
            if(i>maxend) return -1;
            if(i>currend)
            {
                taps++;
                currend=maxend;
            }
            maxend=max(v[i],maxend);
        }
        return taps;
    }
};