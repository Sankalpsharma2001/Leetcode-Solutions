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
    int x;
    void dfs(TreeNode* root,long &ans)
    {
        if(!root) return;
        if(root->val>x && root->val<ans)
        {
            ans=root->val;
        }
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    int findSecondMinimumValue(TreeNode* root) {
        x=root->val;
        long ans=LONG_MAX;
        dfs(root,ans);
        return ans>INT_MAX?-1:ans;
    }
};