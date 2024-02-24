class Solution {
public:
    void tellSecret(int person,unordered_map<int,vector<int>> &g, vector<bool>&visited,unordered_set<int> &s){
        for(int ele:g[person]){
            if(!visited[ele]){
                s.insert(ele);
                visited[ele]=true;
                tellSecret(ele,g,visited,s);
            }
        }
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        // sort(meetings.begin(),meetings.end(), comparator);
        map<int,vector<pair<int,int>>> m;
        for(auto v:meetings){
            m[v[2]].push_back({v[0],v[1]});
        }
        
        unordered_set<int> s;
        s.insert(0);
        s.insert(firstPerson);
        for(auto &[time,v]:m){
            unordered_map<int,vector<int>> g;
            for(auto &[a,b]:v){
                g[a].push_back(b);
                g[b].push_back(a);
            }
            vector<bool> visited(n,false);
            for(auto &[person,v]:g){
                if(!visited[person]&&s.find(person)!=s.end()){
                    tellSecret(person,g,visited,s);
                }
            }
        }
        vector<int> ans;
        for(int ele:s) ans.push_back(ele);
        return ans;
        
    }
};