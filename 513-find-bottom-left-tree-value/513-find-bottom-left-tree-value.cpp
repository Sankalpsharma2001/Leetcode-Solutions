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
    int findBottomLeftValue(TreeNode* root) {
       if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans=root->val;
        while(!q.empty())
        {
            int sz=q.size();
             vector<int> v;
            while(sz--)
            {  
                auto t=q.front();
                q.pop();
                if(t->left)
                {
                    v.push_back(t->left->val);
                    q.push(t->left);
                   
                }
                if(t->right)
                {
                    v.push_back(t->right->val);
                    q.push(t->right);
                }
            }
            if(v.size()>0)
            ans=v[0];
        }
        return ans;
    }
};