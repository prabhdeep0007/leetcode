class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,set<int>> m;
        int s=mat[0].size();
        int c=0;
        
        for(auto v:mat)
        {
            auto it=find(v.begin(),v.end(),0);
            if(it!=v.end()) 
            {
                int i=it-v.begin();
                m[i].insert(c);                
            }
            else
            {
                m[s].insert(c);
            }
            c++;
        }
        vector<int> ans;
        for(auto i:m)
        {
            for(auto j:i.second)
            {
                ans.push_back(j);
                k--;
                if(k==0) break;
            }
             if(k==0) break;
        }
        return ans;
    }
};