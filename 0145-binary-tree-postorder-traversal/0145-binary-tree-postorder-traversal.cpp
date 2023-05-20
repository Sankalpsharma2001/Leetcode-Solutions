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
  
    void reverse(vector<int> &ans)
    {
        int i=0,j=ans.size()-1;
        while(i<j)
        {
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
    if(root==nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *top=s.top();
            s.pop();
          ans.push_back(top->val);
            if(top->left)
                s.push(top->left);
            if(top->right)
                s.push(top->right);
            
            
        }
        reverse(ans);
        return ans;
    }
};