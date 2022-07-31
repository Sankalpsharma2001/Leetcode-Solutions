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
    int sumNumbers(TreeNode* root) {
    if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
             auto it=q.front();
            q.pop();
            TreeNode *t=it.first;
             it.second=it.second*10+t->val;
            if(t->left)
            {
                q.push({t->left,it.second});
            }
            if(t->right)
            {
                q.push({t->right,it.second});
            }
            if(!t->left and !t->right)
            {
                ans+=it.second;
            }
            
        }
        return ans;
    }
};