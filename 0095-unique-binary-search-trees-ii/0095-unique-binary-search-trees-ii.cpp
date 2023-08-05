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
    vector<TreeNode*> fun(int start,int end)
    {
        vector<TreeNode*> ans;
        if(start>end)
        {
            ans.push_back(NULL);
            return ans;
        }
        if(start==end)
        {
            ans.push_back(new TreeNode(start));
            return ans;
        }
        vector<TreeNode*> left,right;
        for(int i=start;i<=end;i++)
        {
            left=fun(start,i-1);
            right=fun(i+1,end);
            for(auto &lnode:left)
            {
                for(auto &rnode:right)
                {
                    TreeNode *node=new TreeNode(i);
                    node->left=lnode;
                    node->right=rnode;
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
       vector<TreeNode*> ans;
     return fun(1,n); 

    }
};