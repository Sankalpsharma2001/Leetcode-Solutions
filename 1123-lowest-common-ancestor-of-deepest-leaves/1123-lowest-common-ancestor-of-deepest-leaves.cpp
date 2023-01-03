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
    int getDepth(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(getDepth(root->left),getDepth(root->right))+1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int left=getDepth(root->left);
        int right=getDepth(root->right);
        if(left==right)
        {
            return root;
        }
        if(left>right)
        {
            return lcaDeepestLeaves(root->left);
        }
        else
        {
            return lcaDeepestLeaves(root->right);
        }
    }
};