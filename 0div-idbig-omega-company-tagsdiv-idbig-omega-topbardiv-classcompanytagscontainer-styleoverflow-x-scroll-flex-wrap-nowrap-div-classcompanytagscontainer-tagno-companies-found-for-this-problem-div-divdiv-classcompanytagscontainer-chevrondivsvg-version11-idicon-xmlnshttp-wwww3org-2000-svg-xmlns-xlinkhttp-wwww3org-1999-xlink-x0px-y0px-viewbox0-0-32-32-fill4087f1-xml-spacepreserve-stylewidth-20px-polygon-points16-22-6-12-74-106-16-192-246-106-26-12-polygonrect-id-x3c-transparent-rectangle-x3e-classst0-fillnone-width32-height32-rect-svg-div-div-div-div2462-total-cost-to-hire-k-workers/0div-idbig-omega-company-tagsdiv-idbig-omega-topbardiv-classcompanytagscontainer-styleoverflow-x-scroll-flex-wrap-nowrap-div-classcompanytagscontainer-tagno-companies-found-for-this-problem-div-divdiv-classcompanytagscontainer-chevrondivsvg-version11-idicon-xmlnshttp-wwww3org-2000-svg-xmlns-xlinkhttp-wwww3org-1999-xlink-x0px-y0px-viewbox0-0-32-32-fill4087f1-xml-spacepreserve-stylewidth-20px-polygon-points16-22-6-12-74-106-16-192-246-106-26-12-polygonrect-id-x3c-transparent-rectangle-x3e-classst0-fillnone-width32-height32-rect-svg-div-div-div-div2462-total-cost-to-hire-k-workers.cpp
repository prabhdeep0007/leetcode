class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        long long ans=0;
        int n=costs.size();
        int l=0,r=n-1;
        for(int i=0;i<k;i++)
        {
            while(pq1.size()<candidates&&l<=r)
            {
                pq1.push(costs[l]);
                l++;
            }
            while(pq2.size()<candidates&&r>=l)
            {
                pq2.push(costs[r]);
                r--;
            }
            int a=INT_MAX,b=INT_MAX;
            if(pq1.size())
            {
                a=pq1.top();
            }
            if(pq2.size())
            {
                b=pq2.top();
            }
            if(a<=b)
            {
                pq1.pop();
                ans+=a;
            }
            else 
            {
                pq2.pop();
                ans+=b;
            }
            
        }
        return ans;
    }
};