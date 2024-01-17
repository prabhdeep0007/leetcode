class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        unordered_set<int>s;
       int n=arr.size();
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
      int  ms=m.size();
        for(auto i:m)
        {
            s.insert(i.second);
        }
   
        return ms==s.size();
    }
};