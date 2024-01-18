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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root) return {};
        q.push(root);
        vector<int> ans;
        while(q.size())
        {
            vector<int> level;
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* n=q.front();
                q.pop();
                level.push_back(n->val);
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            ans.push_back(level.back());
        }
        return ans;
    }
};