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
    int i;
    TreeNode* build (vector<int>& postorder,int st,int end)
    {
        if(st>end) return NULL;
        TreeNode *root=new TreeNode(postorder[i]);
        int idx=m[postorder[i--]]; // left side in inorder of this index belong to left of this root
        root->right=build(postorder,idx+1,end);
        root->left=build(postorder,st,idx-1);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       i=postorder.size()-1;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        return build(postorder,0,postorder.size()-1);
        
    }
};