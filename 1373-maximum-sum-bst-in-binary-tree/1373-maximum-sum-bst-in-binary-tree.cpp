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
class NodeValue {
public: 
    int minNode, maxNode, maxSum;
    
    NodeValue(int minNode, int maxNode, int maxSum)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};

class Solution {
    private:
    NodeValue maxSum(TreeNode *root)
    {
        if(!root) return {INT_MAX,INT_MIN,0};
        NodeValue l=maxSum(root->left);
        NodeValue r=maxSum(root->right);
        if(l.maxNode<root->val && r.minNode>root->val)
        {
          sum=max(sum,root->val+l.maxSum+r.maxSum);
            return NodeValue(min(root->val,l.minNode),max(root->val,r.maxNode),root->val+l.maxSum+r.maxSum);
        }
        return {INT_MIN,INT_MAX,max(l.maxSum,r.maxSum)};
    }
public:
    int sum=0;
    int maxSumBST(TreeNode* root) {
        maxSum(root);
        return sum>0?sum:0;
    }
};