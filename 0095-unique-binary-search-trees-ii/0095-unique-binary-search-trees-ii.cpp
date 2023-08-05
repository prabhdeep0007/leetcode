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
    vector<TreeNode*> solve(int start,int end){
       vector<TreeNode*>ans;
        if(start>end) return{ NULL };
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> left=solve(start,i-1);
            vector<TreeNode*> right=solve(i+1,end);
            for(auto l:left)
            {
                for(auto r:right)
                {
                    TreeNode* root=new TreeNode(i,l,r);
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};