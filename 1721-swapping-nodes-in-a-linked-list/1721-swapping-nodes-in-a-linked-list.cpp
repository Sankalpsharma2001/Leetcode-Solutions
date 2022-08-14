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
class Solution {
public:
  
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode* left=head;
        ListNode* right=head;
        ListNode* cur=head;
         int count=1;
        while(cur)
        {
            if(count<k)
            {
                left=left->next;
            }
            if(count>k)
                right=right->next;
            cur=cur->next;
            count++;
        }
        int v=right->val;
        right->val=left->val;
        left->val=v;
        return head;
    }
};