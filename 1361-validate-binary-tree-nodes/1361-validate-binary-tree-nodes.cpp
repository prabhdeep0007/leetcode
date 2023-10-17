class Solution {
public:
    bool dfs(int node,vector<int>& leftChild, vector<int>& rightChild,vector<int>& vis)
    {
       bool l=false,r=false;
       if(leftChild[node]!=-1 && !vis[leftChild[node]])
       {
           vis[leftChild[node]]=true;
           l=dfs(leftChild[node],leftChild,rightChild,vis);
       }
        else if(leftChild[node]==-1 ) l=true;
        else return false;
         if(rightChild[node]!=-1 && !vis[rightChild[node]])
       {
           vis[rightChild[node]]=true;
           r=dfs(rightChild[node],leftChild,rightChild,vis);
       }
        else if(rightChild[node]==-1 ) r=true;
        else return false;
        return l&r;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> vis(n,0);
        int root;
         vector<bool> find(n,false);
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)find[leftChild[i]]=1;
            if(rightChild[i]!=-1)find[rightChild[i]]=1;
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(find[i]!=1)
            {
                root=i;
                count++;
            }
        }
        if(count!=1) return false;
        vis[root]=1;
        if(! dfs(root,leftChild,rightChild,vis)) return false;
        for(int i=0;i<n;i++) if(!vis[i]) return false;
        return true;
    }
};