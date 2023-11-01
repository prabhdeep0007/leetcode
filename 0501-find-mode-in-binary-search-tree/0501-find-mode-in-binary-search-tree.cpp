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
    void inorder(TreeNode* root, int &prev, int &count, int &maxi, vector<int>& ans){
        if(!root) return;
        inorder(root->left,prev,count,maxi,ans);
        if(root->val==prev){
            count++;
        }
        else{
            if(count>maxi){
                ans.clear();
                maxi=count;
                ans.push_back(prev);
            }
            else if(count==maxi){
                ans.push_back(prev);
            }
            count=1;
            prev=root->val;
        }
        inorder(root->right,prev,count,maxi,ans);
    }
    vector<int> findMode(TreeNode* root) {
        int maxi=0;
        vector<int> ans;
        int prev=-1;
        int count=-1;
        inorder(root,prev,count,maxi,ans);
        if(count>maxi){
                ans.clear();
                maxi=count;
                ans.push_back(prev);
        }
        else if(count==maxi){
                ans.push_back(prev);
            }
        return ans;
    }
};