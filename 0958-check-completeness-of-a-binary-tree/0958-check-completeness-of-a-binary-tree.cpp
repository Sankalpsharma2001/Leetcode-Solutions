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
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return true;
        bool flag=false;
         queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto f=q.front();
                q.pop();
                if(f==NULL)
                    flag=true;
                else
                {
                    if(flag)
                        return false;
                    q.push(f->left);
                    q.push(f->right);
                }
            }
        }
        return true;
        
    }
};