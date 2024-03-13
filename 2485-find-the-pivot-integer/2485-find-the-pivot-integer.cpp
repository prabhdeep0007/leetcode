class Solution {
public:
    int pivotInteger(int n) {
        int sum=0,rsum=0; 
        for(int i=1;i<=n;i++) sum+=i;
       for(int i=n;i>0;i--)
       {
           rsum+=i;
           if(rsum==sum) return i;
          sum-=i;
       }
        return -1;
    }
};