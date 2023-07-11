/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeparent(TreeNode* root,map<TreeNode*,TreeNode*>& parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            TreeNode* r=q.front();
            q.pop();
            if(r->left) 
            {
                parent[r->left]=r;
                q.push(r->left);
            }
            if(r->right)
            {
                parent[r->right]=r;
                q.push(r->right);
            }
            
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>parent;
        map<TreeNode*,bool> visited;
        makeparent(root,parent);
        queue<TreeNode*> q;
        q.push(target);
        int c=0;
        while(q.size())
        {
            int size=q.size();
            if(c==k) break;
            for(int i=0;i<size;i++)
            {
            TreeNode* r=q.front();
            q.pop();
            visited[r]=1;
            if(r->left &&!visited[r->left]) 
            {
                q.push(r->left);
            }
            if(r->right &&!visited[r->right])
            {   
                q.push(r->right);
            }
            if(parent[r] &&!visited[parent[r]])
            {
                q.push(parent[r]);
            }
            }
            c++;
        }
        vector<int> ans;
        while(q.size())
        {
            TreeNode* r=q.front();
            q.pop();
            ans.push_back(r->val);
        }
     return ans;   
    }
};