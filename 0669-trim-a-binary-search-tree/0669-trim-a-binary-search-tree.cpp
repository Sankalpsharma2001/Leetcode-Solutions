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
    TreeNode* trimBst(TreeNode* root,int low,int high)
    {
        
        // O(logn) approach
        if(root==NULL)
            return root;
        if(root->val>=low && root->val<=high)
        {
            root->left=trimBst(root->left,low,high);
            root->right=trimBst(root->right,low,high);
        }
        if(root->val<low)
        {
            return trimBst(root->right,low,high);
        }
        if(root->val>high)
        {
            return trimBst(root->left,low,high);
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
       return trimBst(root,low,high);
    }
};