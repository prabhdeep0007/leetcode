class Solution {
public:
    bool judgeSquareSum(int c) {
        long i=0,j=sqrt(c);
        while(i<=j)
        {
            if((i*i+j*j)==c)
            {
                return true;
            }
            else if(c>(i*i+j*j)) i++;
            else j--;
        }
        return false;
    }
};