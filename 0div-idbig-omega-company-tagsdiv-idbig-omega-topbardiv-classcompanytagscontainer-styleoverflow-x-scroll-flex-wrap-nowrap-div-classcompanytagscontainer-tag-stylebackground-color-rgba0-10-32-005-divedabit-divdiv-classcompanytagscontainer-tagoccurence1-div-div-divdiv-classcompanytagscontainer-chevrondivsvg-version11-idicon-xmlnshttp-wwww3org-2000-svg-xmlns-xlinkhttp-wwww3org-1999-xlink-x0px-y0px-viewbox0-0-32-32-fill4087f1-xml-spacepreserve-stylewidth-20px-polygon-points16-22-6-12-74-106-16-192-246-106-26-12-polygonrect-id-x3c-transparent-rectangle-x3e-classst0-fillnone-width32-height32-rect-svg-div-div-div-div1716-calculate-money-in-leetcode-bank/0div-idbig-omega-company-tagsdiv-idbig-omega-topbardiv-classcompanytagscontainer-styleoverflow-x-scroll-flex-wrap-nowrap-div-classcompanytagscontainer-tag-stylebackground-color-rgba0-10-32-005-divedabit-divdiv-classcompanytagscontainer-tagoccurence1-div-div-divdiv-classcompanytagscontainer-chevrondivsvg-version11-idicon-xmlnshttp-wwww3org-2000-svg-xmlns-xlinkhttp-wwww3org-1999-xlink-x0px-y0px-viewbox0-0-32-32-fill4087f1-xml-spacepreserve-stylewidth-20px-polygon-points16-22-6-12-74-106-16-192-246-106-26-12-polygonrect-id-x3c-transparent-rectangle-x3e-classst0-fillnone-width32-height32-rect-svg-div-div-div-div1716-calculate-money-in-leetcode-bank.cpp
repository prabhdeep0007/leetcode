class Solution {
public:
    int totalMoney(int n) {
        int ans=0,prev=0,curr=0;
        for(int i=0;i<n;i++)
        {
            if(i%7==0)
            {
                ans+=prev+1;
                prev++;
                curr=prev;
            }
            else 
            {
                ans+=curr+1;
                curr++;
            }
        }
        return ans;
    }
};