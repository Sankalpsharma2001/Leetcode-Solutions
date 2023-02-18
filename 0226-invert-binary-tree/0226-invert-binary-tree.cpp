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
    TreeNode* invert(TreeNode* root)
    {
        if(!root)
            return NULL;
        invert(root->left);
        invert(root->right);
        swap(root->left,root->right);
        return root;
        
    }
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};