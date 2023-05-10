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
#define ll long long
class Solution {
public:
    bool isValid(TreeNode *root,ll mn,ll mx)
    {
        if(!root) return true;
        if(root->val<=mn || root->val>=mx) return false;
        return isValid(root->left,mn,root->val) && isValid(root->right,root->val,mx);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MIN,LONG_MAX);
    }
};