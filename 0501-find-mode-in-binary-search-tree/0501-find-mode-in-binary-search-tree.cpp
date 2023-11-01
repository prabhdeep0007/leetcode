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
    void solve( vector<int>&ans,TreeNode* root,int &prev,int& maxi,int& count)
    {
        if(!root) return;
        solve(ans,root->left,prev,maxi,count);
         
        if(prev!=root->val)  count=1;
        else if(prev==root->val) count++;
        if(count>maxi)
        {
            ans.clear();
            maxi=count;
            ans.push_back(root->val);
        }
        else if(count==maxi)
        {
            ans.push_back(root->val);
            
        }
        prev=root->val;
         solve(ans,root->right,prev,maxi,count);
        
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int count=0,maxi=-1,prev=-1;
        solve(ans,root,prev,maxi,count);
        return ans;
    }
};