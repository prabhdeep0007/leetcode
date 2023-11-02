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
       pair<int,int> sumcount(TreeNode* root,int &ans)
       {
           if(!root) return {0,0};
            pair<int,int> p1=sumcount(root->left,ans);
            pair<int,int> p2=sumcount(root->right,ans);
           int sum=root->val+p1.first+p2.first;
           int count=1+p1.second+p2.second;
           if(root->val==sum/count) ans++;
            return {sum,count};
       }       
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        sumcount(root,ans);
        return ans;
    }
};