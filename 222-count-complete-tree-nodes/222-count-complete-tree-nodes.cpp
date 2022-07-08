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
    int left(TreeNode* root)
    {
        if(!root) return 0;
        int c=0;
        while(root)
        {
            root=root->left;
          c++;
        }
        return c;
    }
     int right(TreeNode* root)
    {
        if(!root) return 0;
        int c=0;
        while(root)
        {
            root=root->right;
          c++;
        }
        return c;
    }
    int solve(TreeNode* root)
    {
        if(!root) return 0;
        int l=left(root);
        int r=right(root);
        if(l==r)
            return (1<<l)-1;
        return solve(root->left)+solve(root->right)+1;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return solve(root);
    }
};