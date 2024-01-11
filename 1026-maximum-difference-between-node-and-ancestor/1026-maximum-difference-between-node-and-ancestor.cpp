class Solution {
public:
    int solve(TreeNode* root,vector<int>& prev)
    {
        if(!root) return 0;
        int a=0,b=0,c=0;
        for(int i=0;i<prev.size();i++)
        {
           c=max(c,abs(prev[i]-root->val)); 
        }
        prev.push_back(root->val);
        a=solve(root->left,prev);
        b=solve(root->right,prev);
        prev.pop_back();
        return max({a,b,c});
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int> v;
        v.push_back(root->val);
        return max(solve(root->left,v),solve(root->right,v));
    }
};