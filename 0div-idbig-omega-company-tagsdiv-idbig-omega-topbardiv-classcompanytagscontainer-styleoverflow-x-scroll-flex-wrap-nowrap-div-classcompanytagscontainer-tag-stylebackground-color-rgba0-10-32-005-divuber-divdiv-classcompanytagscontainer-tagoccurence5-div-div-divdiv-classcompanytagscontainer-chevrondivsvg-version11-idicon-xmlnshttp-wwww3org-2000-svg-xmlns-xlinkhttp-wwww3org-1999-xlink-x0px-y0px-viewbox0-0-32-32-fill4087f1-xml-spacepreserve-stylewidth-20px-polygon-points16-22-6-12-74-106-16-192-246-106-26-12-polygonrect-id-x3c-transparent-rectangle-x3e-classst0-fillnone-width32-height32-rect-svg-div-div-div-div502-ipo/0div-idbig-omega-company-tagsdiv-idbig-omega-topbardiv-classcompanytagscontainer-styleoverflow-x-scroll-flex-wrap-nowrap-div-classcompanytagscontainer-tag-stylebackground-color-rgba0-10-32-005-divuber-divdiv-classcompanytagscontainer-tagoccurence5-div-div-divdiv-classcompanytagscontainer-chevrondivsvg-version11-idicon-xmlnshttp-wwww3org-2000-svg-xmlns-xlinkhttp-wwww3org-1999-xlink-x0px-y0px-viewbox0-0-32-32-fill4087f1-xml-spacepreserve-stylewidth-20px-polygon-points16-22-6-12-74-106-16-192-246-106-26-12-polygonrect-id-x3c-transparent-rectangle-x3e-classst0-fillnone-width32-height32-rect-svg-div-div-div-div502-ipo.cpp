class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
      vector<pair<int,int>> v;
        int n=profit.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({capital[i],profit[i]});
        }
        sort(v.begin(),v.end());
        int i=0;
        priority_queue<int> maxprofit;
        while(k--)
        {
            while(i<n && w>=v[i].first) 
            {
                maxprofit.push(v[i].second);
                i++;
            }
            if(!maxprofit.empty())
            {
                w+=maxprofit.top();
                maxprofit.pop();
            }
      }
         return w;
    }
};