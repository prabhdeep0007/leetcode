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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while(st.size())
        {
         root=st.top();
         ans.push_back(root->val);
         st.pop();
         if(root->left) st.push(root->left);
            if(root->right) st.push(root->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};