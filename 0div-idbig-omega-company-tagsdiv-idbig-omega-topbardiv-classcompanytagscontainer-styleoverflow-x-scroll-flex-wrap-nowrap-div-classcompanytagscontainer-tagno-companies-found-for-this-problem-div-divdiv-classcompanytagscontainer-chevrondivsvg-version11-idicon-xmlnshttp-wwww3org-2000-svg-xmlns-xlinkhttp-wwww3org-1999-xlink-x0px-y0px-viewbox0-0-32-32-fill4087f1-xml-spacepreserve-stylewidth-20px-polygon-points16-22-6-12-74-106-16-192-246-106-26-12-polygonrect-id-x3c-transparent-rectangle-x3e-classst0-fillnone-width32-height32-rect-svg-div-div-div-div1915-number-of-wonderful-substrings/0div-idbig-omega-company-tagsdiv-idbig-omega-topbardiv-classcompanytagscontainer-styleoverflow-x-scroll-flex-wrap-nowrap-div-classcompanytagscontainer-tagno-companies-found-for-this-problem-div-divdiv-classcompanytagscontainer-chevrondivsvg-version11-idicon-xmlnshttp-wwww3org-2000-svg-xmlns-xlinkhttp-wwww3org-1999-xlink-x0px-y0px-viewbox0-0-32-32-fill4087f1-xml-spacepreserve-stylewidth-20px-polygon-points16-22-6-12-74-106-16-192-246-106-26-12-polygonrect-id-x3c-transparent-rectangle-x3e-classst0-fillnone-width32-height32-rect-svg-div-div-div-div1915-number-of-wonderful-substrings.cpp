class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<long long,long long> m;
        long long xorr=0,ans=0;
        m[0]=1;
        for(auto i:word)
        {
            xorr^=(1<<(i-'a'));
            ans+=m[xorr];
            for(int j=0;j<10;j++)
            {
              ans+=m[xorr^(1<<j)];
            }
              m[xorr]++;
        }
       
        return ans;
    }
};