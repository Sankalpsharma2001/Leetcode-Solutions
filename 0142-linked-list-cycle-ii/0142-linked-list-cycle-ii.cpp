/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       if(!head) return NULL;
        ListNode *fast=head,*slow=head;
       
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        if(!fast || fast->next==NULL) return NULL;
        slow=head;
        int pos=0;
        while(slow!=fast)
        {
            fast=fast->next;
            slow=slow->next;
            pos++;
        }
        return slow;
        
    }
};