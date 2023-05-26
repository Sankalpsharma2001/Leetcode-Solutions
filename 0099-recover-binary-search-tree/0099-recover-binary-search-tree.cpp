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
    TreeNode *a=NULL,*b=NULL,*pre=new TreeNode(INT_MIN);
    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root->left);
        if(a==NULL && pre->val>root->val)
        {
            a=pre;
        }
        if(a!=NULL && pre->val>root->val)
        {
            b=root;
        }
        pre=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
       
        inorder(root);
        int t=a->val;
        a->val=b->val;
        b->val=t;
    }
};