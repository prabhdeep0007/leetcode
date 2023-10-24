class Solution {
public:
   
    vector<int> preorderTraversal(TreeNode* root) {
     vector<int> ans;
      stack<TreeNode*> st;
        while(true)
        {
            if(root!=NULL)
            {
             ans.push_back(root->val);
             st.push(root);
             root=root->left;
            }
            else
            {
                if(st.empty()) break;
                root=st.top();
                st.pop();
                root=root->right;
            }
        }
        return ans;
    }
};