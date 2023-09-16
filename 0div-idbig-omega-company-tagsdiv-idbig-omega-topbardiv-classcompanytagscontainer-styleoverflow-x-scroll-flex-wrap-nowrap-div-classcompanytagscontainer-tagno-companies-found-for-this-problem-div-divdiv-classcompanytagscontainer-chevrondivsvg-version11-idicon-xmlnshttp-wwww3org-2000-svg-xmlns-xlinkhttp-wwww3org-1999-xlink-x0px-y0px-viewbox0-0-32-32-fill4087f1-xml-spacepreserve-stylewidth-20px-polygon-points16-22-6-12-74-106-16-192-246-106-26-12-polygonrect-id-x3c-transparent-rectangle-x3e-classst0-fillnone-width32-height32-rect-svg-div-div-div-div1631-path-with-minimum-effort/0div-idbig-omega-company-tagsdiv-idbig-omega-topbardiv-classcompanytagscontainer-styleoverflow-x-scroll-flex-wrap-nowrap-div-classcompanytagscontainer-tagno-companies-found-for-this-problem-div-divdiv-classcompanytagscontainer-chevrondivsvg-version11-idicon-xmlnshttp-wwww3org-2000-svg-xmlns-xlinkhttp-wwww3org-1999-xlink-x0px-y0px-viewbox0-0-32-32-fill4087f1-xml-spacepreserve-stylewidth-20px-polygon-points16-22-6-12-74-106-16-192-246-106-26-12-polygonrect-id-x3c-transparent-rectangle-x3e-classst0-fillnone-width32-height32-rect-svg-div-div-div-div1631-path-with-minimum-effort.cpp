class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(pq.size())
        {
            auto it=pq.top();
            int r=it.second.first;
            int c=it.second.second;
            if(r==n-1 && c==m-1) break;
            pq.pop();
            if(r>=1)
            {
                int t=abs(heights[r][c]-heights[r-1][c]);
                t=max(dist[r][c],t);
                if(t<dist[r-1][c])pq.push({t,{r-1,c}});
                dist[r-1][c]=min(dist[r-1][c],t);
            }
              if(c>=1)
            {
                int t=abs(heights[r][c]-heights[r][c-1]);
                t=max(dist[r][c],t);
                 if(t<dist[r][c-1])pq.push({t,{r,c-1}});
                dist[r][c-1]=min(dist[r][c-1],t);
            }
              if(r<n-1)
            {
                int t=abs(heights[r][c]-heights[r+1][c]);
                t=max(dist[r][c],t);
                if(t<dist[r+1][c])pq.push({t,{r+1,c}});
                dist[r+1][c]=min(dist[r+1][c],t);
            }
              if(c<m-1)
            {
                int t=abs(heights[r][c]-heights[r][c+1]);
                t=max(dist[r][c],t);
                if(t<dist[r][c+1])pq.push({t,{r,c+1}});
                dist[r][c+1]=min(dist[r][c+1],t);
            }
                
        }
        return dist[n-1][m-1];
    }
};