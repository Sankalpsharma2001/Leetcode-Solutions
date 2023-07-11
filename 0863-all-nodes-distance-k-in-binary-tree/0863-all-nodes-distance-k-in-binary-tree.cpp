/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findParent(TreeNode *root,TreeNode *p,map<TreeNode*,TreeNode*> &par)
    {
        if(!root) return;
        par[root]=p;
        findParent(root->left,root,par);
        findParent(root->right,root,par);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> par;
        findParent(root,NULL,par);
         par[root]=NULL;
     
        map<TreeNode*,int> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=1;
        int dis=0;
        while(!q.empty() && k--)
        {
             
            int sz=q.size();
            while(sz--)
            {
                TreeNode *node=q.front();
                q.pop();
                    
                vis[node]=1;
             
                if(node->left && !vis[node->left])
                {
                    q.push(node->left);
                }
                if(node->right && !vis[node->right])
                {
                    q.push(node->right);
                }
                if(par[node] && !vis[par[node]])
                {
                  
                    q.push(par[node]);
                }
            }
           
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};