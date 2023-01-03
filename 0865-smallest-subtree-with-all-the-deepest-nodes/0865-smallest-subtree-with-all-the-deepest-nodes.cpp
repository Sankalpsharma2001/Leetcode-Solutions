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
    TreeNode *lca(TreeNode *root,TreeNode *left,TreeNode *right)
    {
        if(root==NULL)
            return NULL;
        if(root==left || root==right)
            return root;
        TreeNode *l=lca(root->left,left,right);
        TreeNode *r=lca(root->right,left,right);
        if(l && r)
            return root;
        if(!l)
            return r;
        return l;
            
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
       if(!root || (!root->left && !root->right)) return root;
        TreeNode* left=NULL,*right=NULL;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode *node=q.front();
                q.pop();
                if(i==0)
                {
                    left=node;
                }
                if(i==sz-1)
                {
                    right=node;
                }
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
        }
        return lca(root,left,right);
    }
};