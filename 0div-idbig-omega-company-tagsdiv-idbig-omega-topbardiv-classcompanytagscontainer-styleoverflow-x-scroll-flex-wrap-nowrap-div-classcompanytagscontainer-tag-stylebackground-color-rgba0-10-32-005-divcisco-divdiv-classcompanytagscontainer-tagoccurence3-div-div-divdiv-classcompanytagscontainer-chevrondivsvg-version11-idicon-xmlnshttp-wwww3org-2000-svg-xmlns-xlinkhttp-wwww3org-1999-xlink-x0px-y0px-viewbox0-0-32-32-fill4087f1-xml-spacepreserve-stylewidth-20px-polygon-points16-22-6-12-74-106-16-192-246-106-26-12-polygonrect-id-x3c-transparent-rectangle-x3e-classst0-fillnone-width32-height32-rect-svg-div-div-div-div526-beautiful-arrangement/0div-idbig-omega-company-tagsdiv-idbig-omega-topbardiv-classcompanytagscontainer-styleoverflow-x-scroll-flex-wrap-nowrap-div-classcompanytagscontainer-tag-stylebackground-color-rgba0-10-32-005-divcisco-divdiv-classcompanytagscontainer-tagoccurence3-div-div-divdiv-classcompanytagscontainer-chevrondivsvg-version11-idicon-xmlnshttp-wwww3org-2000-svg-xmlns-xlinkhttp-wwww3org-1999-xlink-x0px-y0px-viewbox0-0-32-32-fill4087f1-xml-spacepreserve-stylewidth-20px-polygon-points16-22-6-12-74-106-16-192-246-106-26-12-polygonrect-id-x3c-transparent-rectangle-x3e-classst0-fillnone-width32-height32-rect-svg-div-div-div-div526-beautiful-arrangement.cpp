class Solution {
public:
    bool isvalid(int i,int a)
    {
        return (a%(i+1))==0|| ((i+1)%a)==0;
    }
    int solve(int i,int &n,vector<int>&vis)
    {
        if(i==n) return 1;
        int count=0;
        for(int a=1;a<=n;a++)
        {
         
            if(!vis[a]&&isvalid(i,a)) 
            {
            vis[a]=1;
            count+=solve(i+1,n,vis);
            vis[a]=0;
            }
        }

        return count;
    }
    int countArrangement(int n) {
        vector<int> vis(n+1,0);
      return solve(0,n,vis);
    }
};