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
    bool isEvenOddTree(TreeNode* root) {
        if(not(root->val&1)) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(q.size())
        {
            int n=q.size();
            if(level&1)
            {
            int prev=-1;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(prev==-1)
                {
                  if(not(node->val&1))  prev=node->val;
                  else return false;
                }
                else
                {
                 if(not(node->val&1) && prev>node->val)  prev=node->val;
                  else return false;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            }
            else
            {
          
             int prev=-1;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(prev==-1)
                {
                  if((node->val&1))  prev=node->val;
                  else return false;
                }
                else
                {
                 if((node->val&1) && prev<node->val)  prev=node->val;
                  else return false;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            }
            level++;
        }
        return true;
    }
};