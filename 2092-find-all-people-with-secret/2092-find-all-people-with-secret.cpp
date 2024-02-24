class Solution {
public:
   void dfs(unordered_map<int,vector<int>> &m,int i,unordered_set<int> &s,vector<bool>&vis)
   {
       s.insert(i);
       vis[i]=1;
       for(auto &j:m[i])
       {
           if(not(vis[j]))dfs(m,j,s,vis);
       }
   }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_set<int> s;
        map<int,unordered_map<int,vector<int>>> m;
        s.insert(0);
        s.insert(firstPerson);
        for(auto &v:meetings)
        {
            m[v[2]][v[1]].push_back(v[0]);
            m[v[2]][v[0]].push_back(v[1]);
        }
        for(auto i:m)
        {
            vector<bool> vis(n,0);
            for(auto j:i.second)
            {
                if(not(s.find(j.first)==s.end())&&not(vis[j.first]))
                    dfs(i.second,j.first,s,vis);
            }
        }
        vector<int> ans;
        for(auto&i:s) ans.push_back(i);
            return ans;
    }
};