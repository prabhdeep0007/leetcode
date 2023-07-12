class Solution {
public:
    bool leadstoterminal(vector<int> &dp,vector<bool>&visited,vector<vector<int>>& graph,int i)
    {
     if(dp[i]!=-1) return dp[i];
     if(visited[i]) return dp[i]=false;
     visited[i]=true;
     for(int ele:graph[i]){
            if(!leadstoterminal(dp,visited,graph,ele)){
                return dp[i]=false;
            }
        }
        return dp[i]=true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     int n=graph.size();
        vector<int> dp(n,-1);
        vector<bool> visited(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(leadstoterminal(dp,visited,graph,i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};