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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            root=new TreeNode(val);
                return root;
        }
        TreeNode *t=root;
        
        TreeNode *pre=NULL;
        while(t)
        {
            if(t->val>val)
            {
                pre=t;
                t=t->left;
            }
            else if(t->val<val)
            {
                pre=t;
                t=t->right;
            }
        }
        if(pre->val<val)
        {
            pre->right=new TreeNode(val);
        }
       else
       {
            pre->left=new TreeNode(val);
           
       }
       return root; 
        
    }
};