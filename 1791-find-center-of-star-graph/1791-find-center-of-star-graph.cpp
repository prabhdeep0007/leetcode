class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> indegree(edges.size()+2);
        for(auto v:edges)
        {
            indegree[v[0]]++;
            indegree[v[1]]++;
        }
        for(int i=1;i<=edges.size()+1;i++)
        {
            if(indegree[i]==edges.size()) return i;
        }
        return 1;
    }
};