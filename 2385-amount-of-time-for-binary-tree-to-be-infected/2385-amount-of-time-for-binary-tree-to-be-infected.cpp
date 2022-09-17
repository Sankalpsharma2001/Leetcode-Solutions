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
     TreeNode *targ;
  void find(TreeNode* root,TreeNode* pre,map<TreeNode*,TreeNode*> &m,int target)
  { if(!root) return;
   if(root->val==target)
   targ=root;
   
      m[root]=pre;
  
      if(root->left)
      find(root->left,root,m,target);
  
      if(root->right)
       find(root->right,root,m,target);
      
  }
  
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> m;
       find(root,NULL,m,start);   
       queue<TreeNode*> q;
       q.push(targ);
       map<TreeNode*,int> vis;
       vis[targ]=1;
       int time=0;
       while(!q.empty())
       {
           int sz=q.size();
           bool flag=false;
           while(sz--)
          {
              TreeNode *t=q.front();
              q.pop();
              if(t->left and !vis[t->left])
              {
                  q.push(t->left);
                  vis[t->left]=1;
                  flag=true;
              }
              if(t->right and !vis[t->right])
              {
                  q.push(t->right);
                  vis[t->right]=1;
                  flag=true;
              }
              if(m[t] and !vis[m[t]])
              {
                  q.push(m[t]);
                  vis[m[t]]=1;
                  flag=true;
              }
          }
          if(flag) time++;
       }
       return time;
    }
};