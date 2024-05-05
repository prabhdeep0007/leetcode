class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=beginWord.size();
        unordered_set<string> s(begin(wordList),end(wordList));
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(q.size())
        {
            auto [a,b]=q.front();
            q.pop();
            if(a==endWord) return b;
                for(int i=0;i<n;i++)
                {
                    string temp=a;
                    for(char j='a';j<='z';j++)
                    {
                      temp[i]=j;
                        if(s.find(temp)!=s.end())
                        {
                            q.push({temp,b+1});
                            s.erase(temp);
                        }
                    }
                }   
            }
            return 0;
    }
};