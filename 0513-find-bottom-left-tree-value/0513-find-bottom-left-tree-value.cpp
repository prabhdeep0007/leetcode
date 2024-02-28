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
    int ans=0,currlevel=0;
    void dfs(TreeNode* root,int level)
    {
        if(not root)  return;
        if(level>currlevel) 
        {
            ans=root->val;
            currlevel=level;
        }
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        ans=root->val;
        dfs(root,0);
        return ans;
        
    }
};