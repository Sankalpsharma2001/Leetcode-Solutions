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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        queue< pair< TreeNode*,pair<int,vector<int> > > > q;
    vector<vector<int>> ans;
    if(!root)
        return ans;
        q.push({root,{root->val,{root->val}}});
        while(!q.empty())
        {
            auto f=q.front();
            q.pop();
            TreeNode *t=f.first;
            int c=f.second.first;
            vector<int> v=f.second.second;
            if(!t->left and !t->right and c==targetSum)
            {
                ans.push_back(v);
            }
            if(t->left)
            {
                vector<int> l=v;
                l.push_back(t->left->val);
                q.push({t->left,{c+t->left->val,l}});
                
            }
             if(t->right)
            {
                vector<int> r=v;
                r.push_back(t->right->val);
                q.push({t->right,{c+t->right->val,r}});
                
            }
        }
        return ans;
    }
};