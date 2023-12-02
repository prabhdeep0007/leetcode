class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> indegree(n,0);
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                m[graph[i][j]].push_back(i);
            }
            indegree[i]=graph[i].size();
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(q.size())
        {
            int t=q.front();
            ans.push_back(t);
            q.pop();
            for(auto i:m[t])
            {
                if(--indegree[i]==0)
                {
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};