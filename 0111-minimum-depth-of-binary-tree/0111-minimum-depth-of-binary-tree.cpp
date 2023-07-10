class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int left=INT_MAX,right=INT_MAX;
        if(root->left)left=minDepth(root->left);
        if(root->right)right=minDepth(root->right);
        if(!root->left && !root->right) return 1;
        return min(left,right)+1;
    }
};