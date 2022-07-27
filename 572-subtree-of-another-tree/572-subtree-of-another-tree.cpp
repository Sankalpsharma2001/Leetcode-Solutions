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
   bool check(TreeNode *root,TreeNode *t)
   {
       if(!root and !t)
           return true;
       if(!root or !t)
           return false;
       if(root->val!=t->val) return false;
       return check(root->left,t->left) and check(root->right,t->right);
   }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      
        if(!root)
         return false;
        if(root->val==subRoot->val)
        {
            if(check(root,subRoot))
                return true;
           
        }
       return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
        
        
    }
};