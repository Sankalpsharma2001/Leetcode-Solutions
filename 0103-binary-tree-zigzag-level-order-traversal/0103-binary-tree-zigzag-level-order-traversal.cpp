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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        queue<TreeNode *> q;
        if(!root) return ans;
        q.push(root);
        ans.push_back({root->val});
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> v;
            while(sz--)
            {
                TreeNode *node=q.front();
                q.pop();
                if(node->left)
                {
                    v.push_back(node->left->val);
                    q.push(node->left);
                }
                if(node->right)
                {
                    
                    v.push_back(node->right->val);
                    q.push(node->right);
                }
            }
            if(v.size()==0) break;
            if(level%2==0)
                reverse(v.begin(),v.end());
            ans.push_back(v);
           level++;
        }
          return ans;
    }
  
};