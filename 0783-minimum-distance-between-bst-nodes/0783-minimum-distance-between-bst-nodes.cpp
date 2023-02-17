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
    int ans=INT_MAX;
    void solve(TreeNode *root,int &pre)
    {
        if(!root)
            return;
       solve(root->left,pre);
        if(pre!=-1)
        ans=min(ans,root->val-pre);
        pre=root->val;
        solve(root->right,pre);
        
    }
    int minDiffInBST(TreeNode* root) {
   int pre=-1;
        solve(root,pre);
        return ans;
    }
};