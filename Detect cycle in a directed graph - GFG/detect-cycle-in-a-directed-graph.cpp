//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool solve(int i,vector<int> adj[],vector<int> &vis,vector<int> &pathvis)
    {
        vis[i]=1;
        pathvis[i]=1;
        bool ans=false;
        for(auto j:adj[i])
        {
            if(pathvis[j]) return true;
            else if(!vis[j]) ans|=solve(j,adj,vis,pathvis);
        }
        pathvis[i]=0;
        return ans;
    }
    bool isCyclic(int V, vector<int> adj[]) {
      vector<int> vis(V,0),pathvis(V,0);
      bool ans=false;
      for(int i=0;i<V;i++)
      {
          if(!vis[i]) ans|=solve(i,adj,vis,pathvis);
      }
      return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends