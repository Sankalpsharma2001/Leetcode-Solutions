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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=-1;
        int ans=INT_MIN;
        int l=1;
        while(!q.empty())
        {
            int sz=q.size();
            int s=0;
            while(sz--)
            {
                TreeNode *t=q.front();
                s+=t->val;
                q.pop();
                if(t->left)
                q.push(t->left);
                if(t->right)
                q.push(t->right);
                
            }
            if(s>ans)
            {
                ans=s;
                level=l;
            }
            l++;
        }
        return level;
    }
};