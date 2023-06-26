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
  TreeNode* solve(TreeNode* root, int limit, int sum) {
        if(!root) {
            return root;
        }
        
        if(!root->left  &&  !root->right) {
            if(sum + root->val < limit) {
                return NULL;
            }
            else {
                return root;
            }
        }    
        root->left = solve(root->left, limit, sum + root->val);
        root->right = solve(root->right, limit, sum + root->val);
   
        if(root->left == NULL && root->right == NULL) {
            return NULL;
        }
        return root;  
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return solve(root, limit, 0);
    }
};