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
    bool f;
    int balanced(TreeNode* root)
    {
        if(root==NULL) return 1;
        int l=balanced(root->left);
        
        int r=balanced(root->right);
        if(abs(l-r)>1){f=false; return 0;}
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
      ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        f=true;
        balanced(root);
        return f;
    }
};