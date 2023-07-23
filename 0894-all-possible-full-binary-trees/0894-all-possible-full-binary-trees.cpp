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
    unordered_map<int, vector<TreeNode *>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if(n<1 or n%2==0)
        {
            return ans;
        }
         if (dp.find(n) != dp.end()) {
            
            return dp[n];
        }
        if(n==1)
        {
            ans.push_back(new TreeNode(0));
            dp[1]=ans;
            return ans;
        }
        for(int i=1;i<n;i+=2)
        {
            vector<TreeNode*> left=allPossibleFBT(i);
            vector<TreeNode*> right=allPossibleFBT(n-i-1);
            for(TreeNode* &l:left)
            {
                for(TreeNode* &r:right)
                {
                    TreeNode *root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        dp[n]=ans;
        return ans;
    }
};