class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        int n=deck.size();
        sort(deck.begin(),deck.end());
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            q.push(i);
        }
        for(auto&i:deck)
        {
            ans[q.front()]=i;
            q.pop();
            if(q.size())
            {
            q.push(q.front());
            q.pop();}
        }
        return ans;
    }
};