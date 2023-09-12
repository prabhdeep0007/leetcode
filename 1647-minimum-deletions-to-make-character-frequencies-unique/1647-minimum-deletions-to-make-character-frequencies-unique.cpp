class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m1;
        unordered_map<int,int>m2;
        for(auto c:s)
        {
           m1[c]++; 
        }
        int ans=0;
        for(auto i:m1)
        {
            int f=i.second;
                if(m2[f])
                {
                    while(f)
                    {
                        f--;
                        ans++;
                        if(!(m2[f]))
                             {
                                m2[f]=1;
                                break;
                             }
                     }      
                 }
            else{
                m2[f]=1;
            }
         }
    return ans;
    }
};