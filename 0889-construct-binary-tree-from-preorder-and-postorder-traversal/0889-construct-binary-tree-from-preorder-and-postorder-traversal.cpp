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
    int preidx=0;
    unordered_map<int,int> m;
    TreeNode *build(vector<int> &preorder,int st,int end)
    {
        if(st>end || preidx>=preorder.size()) return NULL;
        TreeNode *root=new TreeNode(preorder[preidx++]);
        if(st==end) return root;
        int idx=m[preorder[preidx]];
        root->left=build(preorder,st,idx);
        root->right=build(preorder,idx+1,end-1);
        return root;
        
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
         for(int i=0;i<postorder.size();i++)
        {
            m[postorder[i]]=i;
        }
        return build(preorder,0,preorder.size()-1);
    }
};