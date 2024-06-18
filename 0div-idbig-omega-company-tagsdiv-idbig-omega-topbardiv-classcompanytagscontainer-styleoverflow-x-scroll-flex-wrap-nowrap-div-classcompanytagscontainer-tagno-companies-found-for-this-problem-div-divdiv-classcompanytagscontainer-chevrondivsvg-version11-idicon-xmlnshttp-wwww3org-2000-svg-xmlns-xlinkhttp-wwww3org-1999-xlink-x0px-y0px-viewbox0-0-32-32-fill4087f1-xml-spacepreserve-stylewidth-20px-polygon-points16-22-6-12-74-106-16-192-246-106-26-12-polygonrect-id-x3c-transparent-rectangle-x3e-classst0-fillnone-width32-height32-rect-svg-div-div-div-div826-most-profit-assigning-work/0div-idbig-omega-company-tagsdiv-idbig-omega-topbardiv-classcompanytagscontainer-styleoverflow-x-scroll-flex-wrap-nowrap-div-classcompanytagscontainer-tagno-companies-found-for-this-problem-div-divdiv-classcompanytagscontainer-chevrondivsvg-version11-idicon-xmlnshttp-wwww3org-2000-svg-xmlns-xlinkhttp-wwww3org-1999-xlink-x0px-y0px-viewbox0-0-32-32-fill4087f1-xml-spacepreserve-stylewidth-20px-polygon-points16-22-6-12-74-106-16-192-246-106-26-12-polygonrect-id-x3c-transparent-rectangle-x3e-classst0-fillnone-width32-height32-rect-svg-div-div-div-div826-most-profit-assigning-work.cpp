class Solution {
public:
    bool static cmp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.first!=b.first) 
            return a.first>b.first;
        else return a.second>b.second;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        for(int i=0;i<profit.size();i++)
        {
            v.push_back({profit[i],difficulty[i]});
        }
        sort(v.begin(),v.end(),cmp); 
        sort(worker.rbegin(),worker.rend());
        int i=0,n=worker.size(),j=0,m=v.size();
        int ans=0;
        while(i<n && j<m)
        {
            if(worker[i]>=v[j].second)
            {
                ans+=v[j].first;
                i++;
            }
            else j++;
            
        }
        return ans;
    }
};