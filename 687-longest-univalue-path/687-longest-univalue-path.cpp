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
    int fun(TreeNode *root,int data)
    {
        if(!root) return 0;
        if(data!=root->val)
            return 0;
        return 1+max(fun(root->left,data),fun(root->right,data));
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int l=fun(root->left,root->val);
        int r=fun(root->right,root->val);
        return max(l+r,max(longestUnivaluePath(root->left),longestUnivaluePath(root->right)));
        
    }
};