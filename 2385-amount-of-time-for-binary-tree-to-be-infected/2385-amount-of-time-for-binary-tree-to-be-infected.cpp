/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void buildgraph(TreeNode*root,unordered_map<int,vector<int>>&m)
    {
        if(!root->left&&!root->right) return;
        if(root->left)
        {
            m[root->val].push_back(root->left->val);
            m[root->left->val].push_back(root->val);
            buildgraph(root->left,m);
        }
        if(root->right)
        {
            m[root->val].push_back(root->right->val);
            m[root->right->val].push_back(root->val);
            buildgraph(root->right,m);
        }
        
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_set<int> s;
        queue<int> q;
        unordered_map<int,vector<int>> m;
        q.push(start);
        s.insert(start);
        buildgraph(root,m);
        int time=0;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
             int node=q.front();
             q.pop();
               for(auto i:m[node])
               {
                  if(s.find(i)==s.end())
                  {
                      s.insert(i);
                      q.push(i);
                  }
               }
            }
         time++;
        }
        return time-1;
    }
};