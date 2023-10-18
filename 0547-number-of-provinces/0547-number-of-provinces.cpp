class Solution {
public:
     void bfs(int node,vector<int> &vis,vector<vector<int>>& isConnected,int &n)
     {
        queue<int> q;
        q.push(node);
        while(q.size())
        {
            int node=q.front();
            q.pop();
            for(int i=1;i<n;i++)
            {
                if(isConnected[node][i]==1 &&!vis[i])
                {
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
     }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i]) 
            {
                bfs(i,vis,isConnected,n);
                count++;
            }
        }
        return count;
    }
};