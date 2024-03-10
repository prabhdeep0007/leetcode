class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n=arr.size();
        auto cmp = [](string a, string b) { 
            if(a.size()==b.size()) return a<b;
            return a.size()<b.size();};
        vector<string> ans(n);
        unordered_map<int,set<string,decltype(cmp)>> m;
        for(int idx=0;idx<n;idx++)
        {
        int n=arr[idx].size();
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=i;j<n;j++)
            {
                temp+=arr[idx][j];
                m[idx].insert(temp);
            }
        }
        }
        for(int i=0;i<n;i++)
        {
       
                for(auto s:m[i])
                {
                   
                        bool a=true;
                        for(int j=0;j<n;j++)
                        {
                         if(i!=j)
                         {
                             if(m[j].find(s)!=m[j].end())
                             {
                                a=false;
                                break;
                             }
                         }
                       }
                       if(a)
                       {
                          ans[i]=s;
                          break;
                       }
                    
                }
        }
        return ans;
    }
};