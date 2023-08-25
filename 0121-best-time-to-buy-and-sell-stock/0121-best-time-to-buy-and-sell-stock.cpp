class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=INT_MIN,mini=INT_MAX,n=prices.size();
        for(int i=0;i<n;i++)
        {
            mini=min(prices[i],mini);
            maxi=max(maxi,prices[i]-mini);
        }
        return maxi;
    }
};