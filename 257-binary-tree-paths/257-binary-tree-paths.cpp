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
    vector<string> ans;
    void solve(TreeNode* root,string s)
    {
        if(!root) return;
        if(!root->left and !root->right)
        {
            s+=to_string(root->val);
            ans.push_back(s);
        return;
        }
        solve(root->left,s+to_string(root->val)+"->");
        solve(root->right,s+to_string(root->val)+"->");
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();
        string s="";
        solve(root,s);
        return ans;
    }
};