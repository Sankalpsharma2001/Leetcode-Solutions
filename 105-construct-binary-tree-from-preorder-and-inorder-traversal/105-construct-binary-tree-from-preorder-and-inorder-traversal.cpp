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
    unordered_map<int,int> m;
    int pre=0;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int st,int end)
    {
        if(st>end)
            return NULL;
        TreeNode *root=new TreeNode(preorder[pre]);
           int idx=m[preorder[pre++]];
        root->left=solve(preorder,inorder,st,idx-1);
        root->right=solve(preorder,inorder,idx+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
       return solve(preorder,inorder,0,inorder.size()-1);
        
    }
};