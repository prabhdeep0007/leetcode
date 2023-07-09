class Solution {
public:
    int largestVariance(string s) {
        unordered_set<char> unique(begin(s),end(s));
        int ans=0;
        for(char a:unique)   
        {
         for(char b:unique)
         {
             for(int i=0;i<2;i++)
                 {
             int cnt1=0,cnt2=0;
             for(char c:s)
             {
                 
                 if(a==b) continue;
                 cnt1+=c==a;
                 cnt2+=c==b;
                 if(cnt1<cnt2) {
                     cnt1=0;
                     cnt2=0;
                 }
                 if(cnt1>0 && cnt2>0) ans=max(ans,cnt1-cnt2);
                     
                }
                 reverse(s.begin(),s.end());
             }
         }
        }
        return ans;
    }
};