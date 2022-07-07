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
        // we are storing index like a heap
        while(!q.empty())
        {
            int sz=q.size();
            int s=q.front().second;
            int e=q.back().second;
            ans=max(ans,e-s+1);
            while(sz--)
            {
                pair<TreeNode*,ll> t=q.front();
                q.pop();
                TreeNode *temp=t.first;
                int idx=t.second;
                if(temp->left)
                    q.push({temp->left,1ll*2*idx+1});
                if(temp->right)
                    q.push({temp->right,1ll*2*idx+2});
            }
        }
        return ans;
    }
};