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
    int solve(TreeNode* root)
    {
        if(!root->left and !root->right)
            return root->val;
        int l=solve(root->left);
        int r=solve(root->right);
      if(root->val==2)
      {
          return l|r;
      }
        else
        {
            return l&r;
        }
        return root->val;
    }
    bool evaluateTree(TreeNode* root) {
        // return solve(root);
        if(root->val==1 || root->val==0)
            return root->val;
        bool l=solve(root->left);
        bool r=solve(root->right);
      return (root->val==2)?l|r:l&r;
    }
};