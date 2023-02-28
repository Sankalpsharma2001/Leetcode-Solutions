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
    map<string,int> m;
    string solve(TreeNode* root,vector<TreeNode*> &ans)
    {
        if(!root) return "";
        string s="(";
        s+=( solve(root->left,ans));
       s+=to_string(root->val);
        s+=solve(root->right,ans);
        s+=")";
          m[s]++;
        if(m[s]==2)
            ans.push_back(root);
      
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       m.clear();
        vector<TreeNode*> ans;
       string x= solve(root,ans);
        return ans;
    }
};