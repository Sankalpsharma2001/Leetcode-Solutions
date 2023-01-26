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
    vector<int> ans;
    bool dfs(TreeNode* root, vector<int>& voyage,int &i)
    {
        if(!root) return true;
        if(root->val!=voyage[i++]) return false;
        auto l=root->left,r=root->right;
        if(l && l->val!=voyage[i])
        {
            ans.push_back(root->val);
            swap(l,r);
        }
        return dfs(l,voyage,i) && dfs(r,voyage,i);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int i=0;
        ans.clear();
        return dfs(root,voyage,i)?ans:vector<int>{-1};
    }
};