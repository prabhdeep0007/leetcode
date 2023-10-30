class Solution {
public:
    
    void recurse(unordered_map<int,vector<int>> &graph,int idx, int parent, vector<pair<int,int>> &v, int count, vector<bool> &visited,vector<vector<int>>&ans){
        visited[idx]=true;
        v[idx] = {count,count};
        for(int ele:graph[idx]){
            if(!visited[ele]){
                count++;
                recurse(graph,ele,idx,v,count,visited,ans);
            }
            if(parent!=ele)
                v[idx].second = min(v[ele].second,v[idx].second);
            if(v[idx].first<v[ele].second){
                ans.push_back({idx,ele});
            }
        }
        
    }
    
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>> graph;
        for(auto c:connections){
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        vector<pair<int,int>> v(n,{-1,-1});
        vector<vector<int>> ans;
        vector<bool> visited(n,false);
        recurse(graph,0,-1,v,0,visited,ans);
        return ans;
    }
};