class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int n=piles.size()/3;
        int ans=0;
        while(n)
        {
            piles.pop_back();
            ans+=piles.back();
            piles.pop_back();
            n--;
        }
        return ans;
    }
};