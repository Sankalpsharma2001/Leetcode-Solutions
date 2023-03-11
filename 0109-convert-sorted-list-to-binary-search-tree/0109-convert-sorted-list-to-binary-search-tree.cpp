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
    TreeNode* solve(ListNode* head,ListNode* tail)
    {
        if(head==tail) return NULL;
        ListNode *mid=head,*t=head;
         if(head->next==tail)
        {
            TreeNode *r=new TreeNode(head->val);
            return r;
        }
         while(t!=tail and t->next!=tail)
        {
            mid=mid->next;
            t=t->next->next;
        }
        TreeNode *root=new TreeNode(mid->val);
        root->left=solve(head,mid);
        root->right=solve(mid->next,tail);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        return solve(head,NULL); 
    }
};