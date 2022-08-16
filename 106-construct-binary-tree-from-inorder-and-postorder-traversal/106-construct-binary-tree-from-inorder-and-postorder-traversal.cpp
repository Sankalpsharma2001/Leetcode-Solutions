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
   
    TreeNode *building(vector<int>& inorder,int is,int ie,vector<int>& postorder,int ps,int pe,unordered_map<int,int> &m)
    {
        if(is>ie or ps>pe) return NULL;
        TreeNode *root=new TreeNode(postorder[pe]);
        int idx=m[postorder[pe]];
        int numleft=idx-is;
        root->left=building(inorder,is,idx-1,postorder,ps,ps+numleft-1,m);
        root->right=building(inorder,idx+1,ie,postorder,ps+numleft,pe-1,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        if(inorder.size()!=postorder.size())
            return NULL;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
      return  building(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
    }
};