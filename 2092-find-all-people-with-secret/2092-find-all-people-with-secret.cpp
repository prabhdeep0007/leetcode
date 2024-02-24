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
        map<int,vector<pair<int,int>>> m;
        s.insert(0);
        s.insert(firstPerson);
        for(auto &v:meetings)
        {
            m[v[2]].push_back({v[1],v[0]});
        }
        for(auto &[a,b]:m)
        {
            unordered_map<int,vector<int>> g;
            vector<bool> vis(n,0);
            for(auto &[c,d]:b)
            {
                g[c].push_back(d);
                g[d].push_back(c);
            }
            for(auto &i:g)
            {
                if( not(s.find(i.first)==s.end())&&not(vis[i.first]))
                {
                    dfs(g,i.first,s,vis);
                }
            }
        }
        vector<int> ans;
        for(auto&i:s) ans.push_back(i);
            return ans;
    }
};