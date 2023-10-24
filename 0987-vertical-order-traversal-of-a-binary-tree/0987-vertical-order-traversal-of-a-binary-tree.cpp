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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<int,pair<int,TreeNode*>>> q;
        map<int,map<int,multiset<int>>> m;
        q.push({0,{0,root}});
        while(q.size())
        {
         int level=q.front().first;
         int vertical=q.front().second.first;
         TreeNode* node=q.front().second.second;
         m[vertical][level].insert(node->val);
            q.pop();
         if(node->left)
         {
             q.push({level+1,{vertical-1,node->left}});
         }
         if(node->right)
         {
             q.push({level+1,{vertical+1,node->right}});   
         }
        }
        for(auto it:m)
        {
            vector<int> temp;
            for(auto i:it.second)
            {
                for(int j:i.second)
                {
                    temp.push_back(j);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};