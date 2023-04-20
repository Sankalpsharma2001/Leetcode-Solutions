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

#define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            int s=q.front().second;
            int e=q.back().second;
            ans=max(ans,e-s+1);
            while(sz--)
            {
                auto f=q.front();
                q.pop();
                int idx=f.second;
                if(f.first->left)
                {
                    q.push({f.first->left,(ll)2*idx*1ll+1});
                }
                if(f.first->right)
                {
                    q.push({f.first->right,(ll)2*idx*1ll+2});
                }
            }
        }
        return ans;
    }
};