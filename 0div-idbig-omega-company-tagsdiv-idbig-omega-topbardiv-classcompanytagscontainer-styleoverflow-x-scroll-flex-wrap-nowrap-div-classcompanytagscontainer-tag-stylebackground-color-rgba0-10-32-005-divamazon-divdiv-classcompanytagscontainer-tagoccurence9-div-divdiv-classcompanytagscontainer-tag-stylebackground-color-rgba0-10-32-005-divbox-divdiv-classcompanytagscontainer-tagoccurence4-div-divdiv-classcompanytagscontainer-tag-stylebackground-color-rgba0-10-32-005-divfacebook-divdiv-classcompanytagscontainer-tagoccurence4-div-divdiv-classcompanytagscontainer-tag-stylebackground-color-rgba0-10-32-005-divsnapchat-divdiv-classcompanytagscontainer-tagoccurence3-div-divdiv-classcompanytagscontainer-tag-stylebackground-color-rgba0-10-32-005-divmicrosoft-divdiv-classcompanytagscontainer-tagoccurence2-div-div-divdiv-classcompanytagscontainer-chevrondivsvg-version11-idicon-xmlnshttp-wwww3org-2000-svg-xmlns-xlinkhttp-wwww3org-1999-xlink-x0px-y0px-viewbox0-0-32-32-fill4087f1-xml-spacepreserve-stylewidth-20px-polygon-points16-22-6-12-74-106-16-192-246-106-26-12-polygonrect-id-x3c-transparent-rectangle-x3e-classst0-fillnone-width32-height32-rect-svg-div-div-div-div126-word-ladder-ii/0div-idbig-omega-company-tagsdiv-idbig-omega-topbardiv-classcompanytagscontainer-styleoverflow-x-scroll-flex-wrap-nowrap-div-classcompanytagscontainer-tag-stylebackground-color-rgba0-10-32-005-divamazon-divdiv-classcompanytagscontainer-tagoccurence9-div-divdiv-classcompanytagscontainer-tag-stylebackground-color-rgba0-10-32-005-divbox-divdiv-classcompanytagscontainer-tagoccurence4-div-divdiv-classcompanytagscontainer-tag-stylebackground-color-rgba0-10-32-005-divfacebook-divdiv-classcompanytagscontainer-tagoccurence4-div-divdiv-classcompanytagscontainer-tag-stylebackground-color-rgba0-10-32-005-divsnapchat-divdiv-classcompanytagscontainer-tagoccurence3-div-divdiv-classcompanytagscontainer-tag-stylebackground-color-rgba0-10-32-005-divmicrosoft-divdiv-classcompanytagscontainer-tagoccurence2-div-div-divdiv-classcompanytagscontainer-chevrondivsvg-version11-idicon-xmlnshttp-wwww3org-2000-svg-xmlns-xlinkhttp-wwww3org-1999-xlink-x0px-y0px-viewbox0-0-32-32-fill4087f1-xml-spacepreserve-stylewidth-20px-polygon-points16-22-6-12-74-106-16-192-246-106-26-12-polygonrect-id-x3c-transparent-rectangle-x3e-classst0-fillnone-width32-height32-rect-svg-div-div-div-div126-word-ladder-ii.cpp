class Solution {
public:
            void dfs(string a,int idx,unordered_map<string,int>& m,vector<string> &temp,vector<vector<string>>& ans)
            {
                if(idx==0 && temp.size()>1)
                {
                    reverse(begin(temp),end(temp));
                    ans.push_back(temp);
                    reverse(begin(temp),end(temp));
                }
                for(int i=0;i<a.size();i++)
                    {
                       string t=a;
                        for(char j='a';j<='z';j++)
                        {
                            t[i]=j;
                            if(m.find(t)!=m.end() && m[t]==idx-1)
                            {
                                 temp.push_back(t);
                                 dfs(t,idx-1,m,temp,ans);
                                temp.pop_back();
                            }
                        }
                    }
            }
            vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
                vector<vector<string>> ans;
                unordered_map<string,int> m;
                queue<string> q;
                unordered_set<string> s(wordList.begin(),wordList.end());
                q.push(beginWord);
                m[beginWord]=0;
                s.erase(beginWord);
                while(q.size())
                {
                    string a=q.front();
                    q.pop();
                    if(a==endWord) break;
                    for(int i=0;i<beginWord.size();i++)
                    {
                       string t=a;
                        for(char j='a';j<='z';j++)
                        {
                            t[i]=j;
                            if(s.find(t)!=s.end())
                            {
                                q.push(t);
                                s.erase(t);
                                m[t]=m[a]+1;
                            }
                        }
                    }

                }
                vector<string> temp;
                temp.push_back(endWord);
                dfs(endWord,m[endWord],m,temp,ans);
                return ans;
            }
};