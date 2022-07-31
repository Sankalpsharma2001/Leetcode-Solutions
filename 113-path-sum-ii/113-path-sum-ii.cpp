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
    vector<vector<int>> ans;
    void solve(TreeNode *root,int targetSum,int s,vector<int> v)
    {
        if(!root) return;
        v.push_back(root->val);
        if(!root->left and !root->right and s+root->val==targetSum)
        {
            ans.push_back(v);
            return;
        }
        solve(root->left,targetSum,s+root->val,v);
        solve(root->right,targetSum,s+root->val,v);
    } 
        
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      ans.clear();
        vector<int> v;
        solve(root,targetSum,0,v);
        return ans;
    }
};