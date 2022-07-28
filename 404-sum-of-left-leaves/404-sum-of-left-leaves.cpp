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
    
    int sumOfLeftLeaves(TreeNode* root) {
     ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(root==NULL){
        return 0;
    }
      if(root==NULL){
        return 0;
    }
    queue<TreeNode*>q;
    q.push(root);
    int sum=0;
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                if(!node->left->left&&!node->left->right){
                    sum+=node->left->val;
                }
                else{
                    q.push(node->left);
                }
            }
            if(node->right){
                q.push(node->right);
            }
        }
    }
    return sum;
    }
};