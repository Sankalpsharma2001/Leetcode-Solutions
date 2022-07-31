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
    map<int,vector<pair<int,int>>> m;
    void dfs(TreeNode *root,int c,int r)
    {
        if(!root) return;
        m[c].push_back({r,root->val});
        dfs(root->left,c-1,r+1);
        dfs(root->right,c+1,r+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root,0,0);
        for(auto x:m)
        {
            vector<pair<int,int>> p=x.second;
            sort(p.begin(),p.end());
            vector<int> v;
            for(auto it:p)
            {
                v.push_back(it.second);
            }
            ans.push_back(v);
        }
      
        return ans;
    }
};