class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> s(dictionary.begin(),dictionary.end());
        string ans;
        stringstream ss(sentence);
        string word;
        while(ss>>word)
        {
          string temp="";
          for(auto c:word)
          {
              temp+=c;
              if(s.find(temp)!=s.end()) break;
          }
          ans+=temp;
          ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
    
};