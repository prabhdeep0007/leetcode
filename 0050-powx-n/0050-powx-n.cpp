class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==1)
            return x;
        if(n==0)
            return 1;
        if(n==-1){
            return 1/x;
        }
        double pd2 = myPow(x, n/2);
        if(n&1&&n>0){
            return pd2*pd2*x;
        }
        if(n&1&&n<0){
            return pd2*pd2*(1/x);
        }
        return pd2*pd2;
        
        
    }
};