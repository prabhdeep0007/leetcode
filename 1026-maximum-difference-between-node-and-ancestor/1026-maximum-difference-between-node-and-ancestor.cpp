class Solution {
public:
    int solve(TreeNode* root,int maxi,int mini)
    {
       if(!root) return abs(maxi-mini);
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        return max(solve(root->left,maxi,mini),solve(root->right,maxi,mini));
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int> v;
        v.push_back(root->val);
        return max(solve(root->left,root->val,root->val),solve(root->right,root->val,root->val));
    }
};