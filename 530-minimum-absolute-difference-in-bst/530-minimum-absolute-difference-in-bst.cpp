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
    void solve(TreeNode* root,int &ans,int &mn)
    {
        if(!root) return;
        
        solve(root->left,ans,mn);
        if(mn>=0)
        {
            ans=min(ans,root->val-mn);
        }
        mn=root->val;
        solve(root->right,ans,mn);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        int mn=-1;
        
        solve(root,ans,mn);
            return ans;
    }
};