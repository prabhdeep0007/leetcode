class Solution {
public:
    bool checkStrings(string s1, string s2) {
        map<char,int>odd;
        map<char,int>even;
        for(int i=0;i<s1.size();i+=2)
        {
         even[s1[i]]++;
         even[s2[i]]--;
        }
        for(int i=1;i<s1.size();i+=2)
        {
            odd[s1[i]]++;
            odd[s2[i]]--;
        }
        for(auto m:odd)
        {
            if(m.second!=0) return false;
            cout<<m.second<<"   "<<m.first<<endl;
        }
        cout<<endl;
        for(auto m:even)
        {
              if(m.second!=0) return false;
            cout<<m.second<<" "<<m.first<<endl;
        }
        return true;
    }
};