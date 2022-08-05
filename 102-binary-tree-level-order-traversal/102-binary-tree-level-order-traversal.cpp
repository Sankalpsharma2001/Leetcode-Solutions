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
    void dfs(TreeNode* root,vector<vector<int>> &ans,vector<int> v,int level)
    {
        if(!root) return;
        
        if(level==ans.size())
        ans.push_back({root->val});
        else
            ans[level].push_back(root->val);
        dfs(root->left,ans,v,level+1);
        dfs(root->right,ans,v,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> ans;
        vector<int> v;
        int level=0;
        dfs(root,ans,v,level);
        return ans;
    }
};