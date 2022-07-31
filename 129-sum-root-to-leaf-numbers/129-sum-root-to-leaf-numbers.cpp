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
    void solve(TreeNode *root,int n)
    {
        if(!root) return;
        if(!root->left and !root->right)
        {
            ans+=(n*10+root->val);
        }
        solve(root->left,n*10+root->val);
        solve(root->right,n*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};