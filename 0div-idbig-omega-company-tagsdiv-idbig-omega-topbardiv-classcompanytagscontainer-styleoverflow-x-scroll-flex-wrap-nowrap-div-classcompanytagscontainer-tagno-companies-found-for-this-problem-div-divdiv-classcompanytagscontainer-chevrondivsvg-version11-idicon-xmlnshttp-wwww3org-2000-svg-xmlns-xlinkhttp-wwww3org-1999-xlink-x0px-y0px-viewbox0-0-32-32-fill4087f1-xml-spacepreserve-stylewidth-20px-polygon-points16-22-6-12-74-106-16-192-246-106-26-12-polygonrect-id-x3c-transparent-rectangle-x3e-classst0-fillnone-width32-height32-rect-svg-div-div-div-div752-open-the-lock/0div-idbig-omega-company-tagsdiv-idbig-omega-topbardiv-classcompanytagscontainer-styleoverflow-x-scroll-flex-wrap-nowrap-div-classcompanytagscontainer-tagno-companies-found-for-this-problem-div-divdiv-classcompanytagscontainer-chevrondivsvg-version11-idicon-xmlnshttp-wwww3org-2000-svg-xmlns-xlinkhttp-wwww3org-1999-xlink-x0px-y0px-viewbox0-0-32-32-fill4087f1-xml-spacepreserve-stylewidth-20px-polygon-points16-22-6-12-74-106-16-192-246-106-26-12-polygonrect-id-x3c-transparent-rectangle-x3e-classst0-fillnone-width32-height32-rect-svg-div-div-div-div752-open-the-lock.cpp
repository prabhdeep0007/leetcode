class Solution {
public:
    vector<string> findallsteps(string& s) {
      vector<string> res;
      for (int i = 0; i < 4; ++i) {
        string up = s;
        string down = s;
        up[i] = (up[i] == '9' ? '0' : up[i] + 1);
        down[i] = (down[i] == '0' ? '9' : down[i] - 1);
        res.push_back(up);
        res.push_back(down);
      }
      return res;
    }
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> s(deadends.begin(),deadends.end());
        if(s.find("0000")!=s.end()) return -1;
        q.push("0000");
        int steps=0;
        while(q.size())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                string curr=q.front();
                if(curr==target) return steps;
                q.pop();
                for(auto& t:findallsteps(curr))
                {
                    if(s.find(t)==s.end()) 
                    {
                        if(t==target) return steps+1;
                        q.push(t);
                        s.insert(t);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};