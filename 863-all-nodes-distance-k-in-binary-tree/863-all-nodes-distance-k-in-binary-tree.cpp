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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       map<TreeNode*,TreeNode*> m;
        queue<TreeNode*> q;
        TreeNode *f=NULL;
        q.push(root);
        m[root]=NULL;
        while(!q.empty())
        {
            auto t=q.front();
            q.pop();
            if(t->val==target->val)
                f=target;
            if(t->left)
            {
                q.push(t->left);
                m[t->left]=t;
            }
            if(t->right)
            {
                q.push(t->right);
                m[t->right]=t;
            }
        }
       queue<TreeNode*> q1;
        
        map<TreeNode*,int> vis;
        q1.push(target);
        vis[target]=1;
        int dis=0;
        while(!q1.empty())
        {
            
            int sz=q1.size();
                            if(dis==k) break;

            while(sz--)
            {
                                if(dis==k) break;
               auto x=q1.front();
                vis[x]=1;
                q1.pop();
                if(x->left and !vis[x->left])
                {
                 q1.push(x->left);   
                }
                if(x->right and !vis[x->right])
                {
                    q1.push(x->right);
                }
                if(m[x] and !vis[m[x]])
                    q1.push(m[x]);
            }
            dis++;
        }
            vector<int> ans;
        while(!q1.empty())
        {
            ans.push_back(q1.front()->val);
            q1.pop();
        }
        return ans;
        
    }
};