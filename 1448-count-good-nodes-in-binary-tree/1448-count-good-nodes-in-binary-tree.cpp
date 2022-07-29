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
    int ans=0;
    void solve(TreeNode *root,int mx)
    {
        if(!root)
            return;
        if(root->val>=mx)
        {
            mx=root->val;
            ans++;
        }
        solve(root->left,mx);
        solve(root->right,mx);
       
    }
    int goodNodes(TreeNode* root) {
        solve(root,-1e9);
        return ans;
    }
};