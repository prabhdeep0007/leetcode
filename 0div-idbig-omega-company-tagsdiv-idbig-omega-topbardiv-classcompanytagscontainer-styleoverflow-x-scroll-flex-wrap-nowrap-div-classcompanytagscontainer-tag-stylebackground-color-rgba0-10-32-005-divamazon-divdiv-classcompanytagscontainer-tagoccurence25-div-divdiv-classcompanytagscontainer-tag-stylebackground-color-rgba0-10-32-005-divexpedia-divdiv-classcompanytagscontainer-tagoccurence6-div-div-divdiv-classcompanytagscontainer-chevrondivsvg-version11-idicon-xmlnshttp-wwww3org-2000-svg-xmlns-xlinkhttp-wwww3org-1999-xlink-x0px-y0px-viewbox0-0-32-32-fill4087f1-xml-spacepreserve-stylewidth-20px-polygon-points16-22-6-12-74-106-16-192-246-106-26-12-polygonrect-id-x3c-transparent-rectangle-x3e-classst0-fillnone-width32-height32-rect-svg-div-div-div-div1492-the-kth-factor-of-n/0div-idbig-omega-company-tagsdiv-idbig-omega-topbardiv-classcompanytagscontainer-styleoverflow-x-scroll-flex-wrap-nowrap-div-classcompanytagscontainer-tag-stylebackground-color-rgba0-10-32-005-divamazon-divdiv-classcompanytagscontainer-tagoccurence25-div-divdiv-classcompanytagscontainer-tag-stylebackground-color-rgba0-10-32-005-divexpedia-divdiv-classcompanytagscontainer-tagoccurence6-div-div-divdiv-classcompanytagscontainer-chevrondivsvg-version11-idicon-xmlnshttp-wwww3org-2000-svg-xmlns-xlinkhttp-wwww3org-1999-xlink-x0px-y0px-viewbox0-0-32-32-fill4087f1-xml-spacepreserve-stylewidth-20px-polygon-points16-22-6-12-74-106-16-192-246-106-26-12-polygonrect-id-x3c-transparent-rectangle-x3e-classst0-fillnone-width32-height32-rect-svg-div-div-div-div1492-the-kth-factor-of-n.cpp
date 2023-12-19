class Solution {
public:
    int kthFactor(int n, int k) {
        int ans=-1;
        int i=1;
        while(i<=n+1)
        {
            if(k==0)
            {
                ans=i-1;
                break;
            }
            if(n%i==0) k--;
             i++; 
        }
        return ans;

    }
};