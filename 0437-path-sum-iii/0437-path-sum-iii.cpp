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
 int ans=0;
    void findSum(TreeNode* root,long long int s,int &targetSum,map<long long int,long long int> &m)
    {
       if(!root) return ;
          s+=root->val;
        
        if(m.find(s-targetSum)!=m.end())
            ans+=m[s-targetSum];
        m[s]++;
        findSum(root->left,s,targetSum,m);
        findSum(root->right,s,targetSum,m);
        m[s]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
     if(!root) return 0;
      
        map<long long int,long long int> m;
          m[0]++;
       findSum(root,0,targetSum,m);
        return ans;
    }
};