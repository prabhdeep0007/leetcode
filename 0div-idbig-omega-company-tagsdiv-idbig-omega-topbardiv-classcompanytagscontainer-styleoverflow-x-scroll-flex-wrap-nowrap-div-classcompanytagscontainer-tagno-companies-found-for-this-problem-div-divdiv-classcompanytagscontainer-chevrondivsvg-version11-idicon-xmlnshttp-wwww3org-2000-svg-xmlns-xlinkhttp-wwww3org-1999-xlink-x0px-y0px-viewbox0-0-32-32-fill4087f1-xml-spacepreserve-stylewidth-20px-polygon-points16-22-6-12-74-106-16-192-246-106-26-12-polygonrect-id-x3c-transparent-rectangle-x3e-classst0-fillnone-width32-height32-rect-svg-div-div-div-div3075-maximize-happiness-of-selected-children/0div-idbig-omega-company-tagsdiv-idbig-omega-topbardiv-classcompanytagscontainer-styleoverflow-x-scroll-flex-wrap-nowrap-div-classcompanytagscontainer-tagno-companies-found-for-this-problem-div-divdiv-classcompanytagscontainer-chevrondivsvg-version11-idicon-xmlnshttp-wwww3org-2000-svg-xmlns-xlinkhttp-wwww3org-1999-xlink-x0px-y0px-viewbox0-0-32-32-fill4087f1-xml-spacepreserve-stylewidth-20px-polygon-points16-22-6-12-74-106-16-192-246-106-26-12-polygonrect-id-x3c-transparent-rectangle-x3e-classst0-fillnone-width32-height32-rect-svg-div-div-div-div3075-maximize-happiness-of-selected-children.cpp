class Solution {
public:
    static bool cmp(int &a,int &b)
    {
        return a>b;
    }
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        sort(happiness.begin(),happiness.end(),cmp);
        int sub=0,i=0;
        while(k)
        {
            if(happiness[i]-sub>0)
            {
                ans+=happiness[i]-sub;
            }
            else break;
            i++;
            sub++;
            k--;
        }
        return ans;
    }
};