/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, root, false);
    }
    bool dfs(ListNode* head, TreeNode* root, bool head_match_last) {
        // use up all required elements in head
        if (head == nullptr) {
            return head_match_last;
        }
        // remaining elements in head, but we have reached the leaf
        if (root == nullptr) return false; 
        if (head_match_last) {
            if (head->val != root->val) return false;
            if (dfs(head->next, root->left, true) || dfs(head->next, root->right, true)) {
                return true;
            }
        }
        else {
            if (head->val == root->val) {
                // choose to match current element
                if (dfs(head->next, root->left, true) || dfs(head->next, root->right, true)) {
                    return true;
                }
            }
            // continue to not match current element
            if (dfs(head, root->left, false) || dfs(head, root->right, false)) {
                return true;
            }
        }
        return false;
    }
};