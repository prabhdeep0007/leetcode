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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1) return new TreeNode(val,root,NULL);
        queue<TreeNode*> bfs;
        bfs.push(root);
         while(bfs.size())
        {
            if(depth==2) break;
            depth--;
             int n=bfs.size();
             for(int i=0;i<n;i++)
             {
                 TreeNode* node=bfs.front();
                 bfs.pop();
                 if(node->left) bfs.push(node->left);
                 if(node->right) bfs.push(node->right);
             }
        }
        while(bfs.size())
        {
             TreeNode* node=bfs.front();
             bfs.pop();
             node->left=new TreeNode(val,node->left,NULL);
             node->right=new TreeNode(val,NULL,node->right);
        }
        return root;
    }
};