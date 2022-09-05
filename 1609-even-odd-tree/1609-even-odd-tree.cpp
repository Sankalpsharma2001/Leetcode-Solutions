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
    bool isEvenOddTree(TreeNode* root) {
         vector<TreeNode*> q{root};
    int l = 0;
        while(!q.empty())
        {
            vector<TreeNode*> q1;
            int pre=0;
            for(auto &it:q)
            {
                if(it!=NULL)
                {
                    if(it->val%2==l%2)
                        return false;
                    if(pre and ((l%2==0 and pre>=it->val) or (l%2 and pre<=it->val)))
                        return false;
                    pre=it->val;
                    q1.push_back(it->left);
                    q1.push_back(it->right);
                    
                    
                }
            }
            swap(q,q1);
            l++;
        }
        return true;
    }
};