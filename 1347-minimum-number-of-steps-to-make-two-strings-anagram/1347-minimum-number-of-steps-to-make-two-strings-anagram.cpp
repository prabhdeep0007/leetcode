class Solution {
public:
    int minSteps(string s, string t) {
       vector<int>freq1(26,0),freq2(26,0);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
          freq1[s[i]-'a']++;
          freq2[t[i]-'a']++;
        }
        if(freq1==freq2)return 0;
        int ans=0;
        for(int i=0;i<26;i++)
        {
            ans+=abs(freq1[i]-freq2[i]);
        }
        return ans/2; 
    }
};