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
    TreeNode *lca(TreeNode* root,int a,int b)
    {
        if(!root) return NULL;
        if(root->val==a || root->val==b) return root;
        TreeNode *left=lca(root->left,a,b);
        TreeNode *right=lca(root->right,a,b);
        if(left && right)
            return root;
        if(!left)
            return right;
        if(!right)
        return left;
        return NULL;
    }
    bool search(TreeNode *root,int target,string &s)
    {
        if(!root) return false;
        if(root->val==target) return true;
        
        bool find1=search(root->left,target,s+='L');
        if(find1) return true;
        s.pop_back();
        
         bool find2=search(root->right,target,s+='R');
        if(find2) return true;
        s.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root=lca(root,startValue,destValue);
        string s1="",s2="";
        search(root,startValue,s1);
        search(root,destValue,s2);
        for(auto &it:s1)
        {
            it='U';
        }
        return s1+s2;
        
        
    }
};