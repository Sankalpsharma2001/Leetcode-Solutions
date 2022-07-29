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
    int sumTree(TreeNode* root,unordered_map<int,int> &m,int &mx)
    {
        if(!root) return 0;
        int l=sumTree(root->left,m,mx);
        int r=sumTree(root->right,m,mx);
        int sum=root->val+l+r;
        m[sum]++;
        mx=max(mx,m[sum]);
        return sum;
        
    }
   
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int,int> m;
        int mx=0;
        int x=sumTree(root,m,mx);
       
      
        for(auto x:m)
        {
            if(x.second==mx)
                ans.push_back(x.first);
        }
        return ans;
    }
};