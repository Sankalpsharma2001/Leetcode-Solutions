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
    map<TreeNode*,TreeNode*> parent;
    void find(TreeNode* root,TreeNode* target,TreeNode *par)
    {
        if(!root) return;
      
       
       parent[root]=par;
        find(root->left,target,root);
        
        find(root->right,target,root);
    }
    void findatk(TreeNode* root,int k,vector<int> &ans,vector<int> &vis)
    {
        if(!root) return;
        
        if(k==0 and !vis[root->val])
        { 
   vis[root->val]=1;
            ans.push_back(root->val);
            return;
        }
        
        if(root->left and !vis[root->left->val])
        findatk(root->left,k-1,ans,vis);
        
        if(root->right and !vis[root->right->val])
        findatk(root->right,k-1,ans,vis);
    }
    void findinpar(TreeNode* root,int k,vector<int> &ans,vector<int> &vis)
    {
        if(!root) return;
    
        if(k==0 and !vis[root->val])
        {
            
   vis[root->val]=1;
            ans.push_back(root->val);
        }
        vis[root->val]=1;
        if(root->left and !vis[root->left->val])
            findinpar(root->left,k-1,ans,vis);
        if(root->right and !vis[root->right->val])
            findinpar(root->right,k-1,ans,vis);
        
       if(parent[root] and !vis[parent[root]->val] )
          findinpar(parent[root],k-1,ans,vis);
    }
    void findall(TreeNode* root,int k,vector<int> &ans,vector<int> &vis)
    {
        if(!root) return;
        vis[root->val]=1;
        
        if(k==0)
        {          
          ans.push_back(root->val);
        }
    
        if(root->left and !vis[root->left->val])
            findinpar(root->left,k-1,ans,vis);
        if(root->right and !vis[root->right->val])
            findinpar(root->right,k-1,ans,vis);
        
       if(parent[root] and !vis[parent[root]->val] )
          findinpar(parent[root],k-1,ans,vis);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent.clear();
        vector<int> ans;
        if(!root) return ans;
        if(k==0)
        {ans.push_back(target->val);
            return ans;
        }
        vector<int> vis(501,0);
        // find(root,target,NULL);
       // bfs we can use also
         queue<TreeNode*> q;
        
        q.push(root);
        parent[root] = NULL;
        
        while(!q.empty())
        {
            TreeNode* left = q.front()->left;
            TreeNode* right = q.front()->right;
            TreeNode* parent1 = q.front();
            
            if(left)
            {
                q.push(left);
                parent[left] = parent1;
            }
            if(right)
            {
                q.push(right);
                parent[right] = parent1;
            }
            
            q.pop();    
        }
        findall(target,k,ans,vis);
        // findatk(target,k,ans,vis);
        // findinpar(target,k,ans,vis);
        return ans;
    }
};