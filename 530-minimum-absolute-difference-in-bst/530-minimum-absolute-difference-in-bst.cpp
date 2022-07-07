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
    int ans;
    TreeNode *pre=NULL;
    void solve1(TreeNode* root)
    {
         if(!root) return;
        
        solve1(root->left);
        if(pre)
        {
            ans=min(ans,abs(root->val-pre->val));
        }
        pre=root;
        solve1(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
         ans=INT_MAX;
        int mn=-1;
        solve1(root);
        // solve(root,ans,mn);
            return ans;
    }
};