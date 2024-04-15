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
    int ans=0;
    void preorder(TreeNode* root,string s)
    {
        if(root==nullptr) return;
         s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
          ans+=stoi(s);
            return;
        }
        preorder(root->left,s);
        preorder(root->right,s);
        // s.pop_back();
        
    }
    int sumNumbers(TreeNode* root) {
        
        string s="";
     preorder(root,s);
        return ans;
    }
};