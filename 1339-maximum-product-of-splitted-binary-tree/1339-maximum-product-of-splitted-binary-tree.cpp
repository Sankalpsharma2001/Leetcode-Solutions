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
    long long int s=0,ans=0;
    void sum(TreeNode* root)
    {
        if(!root) return;
        s+=root->val;
        sum(root->left);
        sum(root->right);
    }
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;
        // int l=;
        // int r=solve(root->right);
        int subtree=solve(root->left)+solve(root->right)+root->val;
        ans=max(ans,(s-subtree)*subtree);
        // return l+r+root->val;
        return subtree;
     }
    int mod=1e9+7;
    int maxProduct(TreeNode* root) {
      ans=0;
        sum(root);
        solve(root);
        return ans%mod;
    }
};