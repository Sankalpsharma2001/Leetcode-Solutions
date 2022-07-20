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
        int l=solve(root->left);
        int r=solve(root->right);
        ans=max({ans,(s-l)*l,(s-r)*r});
        return l+r+root->val;
     }
    int mod=1e9+7;
    int maxProduct(TreeNode* root) {
      ans=0;
        sum(root);
        solve(root);
        return ans%mod;
    }
};