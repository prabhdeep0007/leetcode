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
    void dfs(vector<int> & temp,TreeNode* root)
    {
           if(!root) return;
           if(!root->left && !root->right)
           {
             temp.push_back(root->val);
               return;
           }
           dfs(temp,root->left);
           dfs(temp,root->right);
    }
    vector<int> leafsequence(TreeNode*root)
    {
        vector<int> temp;
        dfs(temp,root);
        return temp;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      vector<int> v1= leafsequence(root1),v2=leafsequence(root2);
        return v1==v2;
    }
};