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
    ListNode* removeElements(ListNode* head, int val) {
       if(!head) return head;
        ListNode *pre=NULL,*cur=head;
        while(cur)
        {
            if(head->val==val){head=head->next;pre=cur;cur=head; continue;}
            if(cur->val==val)
            {
                pre->next=cur->next;
              cur=cur->next;
                continue;
            }
            pre=cur;
            cur=cur->next;
        }
        return head;
    }
};