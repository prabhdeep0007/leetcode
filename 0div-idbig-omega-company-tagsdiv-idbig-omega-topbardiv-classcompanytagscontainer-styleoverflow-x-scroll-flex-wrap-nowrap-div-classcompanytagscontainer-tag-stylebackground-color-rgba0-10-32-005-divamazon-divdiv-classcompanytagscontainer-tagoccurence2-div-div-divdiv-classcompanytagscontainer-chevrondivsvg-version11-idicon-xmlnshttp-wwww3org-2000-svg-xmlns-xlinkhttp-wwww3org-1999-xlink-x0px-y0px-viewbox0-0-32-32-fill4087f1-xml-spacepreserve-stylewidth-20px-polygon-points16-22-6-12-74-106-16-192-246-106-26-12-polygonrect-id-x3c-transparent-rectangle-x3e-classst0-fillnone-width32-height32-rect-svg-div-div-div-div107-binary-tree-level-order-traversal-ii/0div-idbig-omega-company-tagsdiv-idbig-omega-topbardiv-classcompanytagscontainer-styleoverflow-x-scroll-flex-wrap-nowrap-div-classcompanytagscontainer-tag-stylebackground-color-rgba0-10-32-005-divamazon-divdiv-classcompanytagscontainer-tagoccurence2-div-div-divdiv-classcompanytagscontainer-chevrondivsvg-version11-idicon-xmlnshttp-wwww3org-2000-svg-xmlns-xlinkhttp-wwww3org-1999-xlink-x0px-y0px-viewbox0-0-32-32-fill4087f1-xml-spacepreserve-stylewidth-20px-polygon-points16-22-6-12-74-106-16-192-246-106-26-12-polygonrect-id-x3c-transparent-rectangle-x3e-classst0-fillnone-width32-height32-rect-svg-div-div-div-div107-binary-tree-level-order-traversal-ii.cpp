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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return{};
        vector<vector<int> >ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            vector<int> temp;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                temp.push_back(t->val);
            }
            ans.push_back(temp);
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};