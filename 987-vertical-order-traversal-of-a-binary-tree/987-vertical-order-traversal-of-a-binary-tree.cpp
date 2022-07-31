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
  
   
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
          map<int,vector<pair<int,int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}}); // val row col
        while(!q.empty())
        {
            auto f=q.front();
            int r=f.second.first;
            int c=f.second.second;
            m[c].push_back({r,f.first->val});
            q.pop();
            if(f.first->left)
            {
                
                q.push({f.first->left,{r+1,c-1}});
            }
            if(f.first->right)
            {
                q.push({f.first->right,{r+1,c+1}});
            }
        }
        for(auto x:m)
        {
            vector<pair<int,int>> p=x.second;
            sort(p.begin(),p.end());
            vector<int> v;
            for(auto it:p)
            {
                v.push_back(it.second);
            }
            ans.push_back(v);
        }
      
        return ans;
    }
};