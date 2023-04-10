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
    void solve(TreeNode* &root,unordered_set<int> &s,vector<TreeNode*> &ans)
    {
        if(!root) return;
        solve(root->left,s,ans);
        solve(root->right,s,ans);
        if(s.find(root->val)!=s.end())
        {
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            root=NULL;
            delete root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
         vector<TreeNode*> ans;
        unordered_set<int> s(to_delete.begin(),to_delete.end());
        solve(root,s,ans);
        if(root) ans.push_back(root);
        return ans;
        
        
    }
};