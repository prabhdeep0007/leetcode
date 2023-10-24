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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return{};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            queue<TreeNode*> level;
            int maxi=INT_MIN;
            while(q.size())
            {
             TreeNode* node=q.front();
                q.pop();
                maxi=max(maxi,node->val);
                if(node->left) level.push(node->left);
                if(node->right) level.push(node->right);
            }
            ans.push_back(maxi);
            q=level;
        }
        return ans;
    }
};