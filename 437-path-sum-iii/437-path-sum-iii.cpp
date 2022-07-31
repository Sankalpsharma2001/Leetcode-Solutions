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
    int findSum(TreeNode* root,long long int s,int targetSum)
    {
        if(!root) return 0;
       long long int cur=s+root->val;
        return (cur==targetSum)+findSum(root->left,cur,targetSum)+findSum(root->right,cur,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
     if(!root) return 0;
        return findSum(root,0,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};