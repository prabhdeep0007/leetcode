class Solution {
public:
    void dfs(int i,unordered_map<int,vector<int>>& adj,vector<int>& ans,unordered_set<int> &s)
    {
        ans.push_back(i);
        s.insert(i);
        for(auto j:adj[i])
        {
            if(s.find(j)==s.end())dfs(j,adj,ans,s);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        unordered_map<int,vector<int>> adj;
        for(auto i:adjacentPairs)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int n=adj.size();
        unordered_set<int> s;
        for(auto i:adj)
        {
            if(i.second.size()==1) 
            {
                dfs(i.first,adj,ans,s);
                break;
            }
        }
        return ans;
    }
};