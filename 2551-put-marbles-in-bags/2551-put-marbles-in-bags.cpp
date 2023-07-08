class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
         int n=weights.size();
        if(n==k || k==1) return 0;
        long long min=0,max=0;
        vector<int> a;
       
        for(int i=0;i<n-1;i++)
        {
            a.push_back(weights[i]+weights[i+1]);
        }
        sort(a.begin(),a.end());
        for(int i=0;i<k-1;i++)
        {
            min+=a[i];
            max+=a[n-i-2];
        }
        return max-min;
    }
};