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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool rotate=false;
        while(q.size())
        {
            vector<int> temp;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
            TreeNode* r=q.front();
            temp.push_back(r->val);
            q.pop();
            if(r->left) q.push(r->left);
            if(r->right)q.push(r->right);
            }
            
            if(rotate) reverse(temp.begin(),temp.end());
            rotate=!rotate;
            ans.push_back(temp);
            
        }
        return ans;
    }
};