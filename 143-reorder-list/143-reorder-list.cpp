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
    ListNode *reverse(ListNode *head)
    {
        ListNode *cur=head,*pre=NULL;
       while(cur)
       {
           ListNode *nxt=cur->next;
           cur->next=pre;
           pre=cur;
           cur=nxt;
       }
        return pre;
    }
    void reorderList(ListNode* head) {
        
        ListNode *slow=head,*fast=head,*pre=NULL;
        while(fast->next and fast->next->next)
        {
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast->next) slow=slow->next;
        ListNode *mid=reverse(slow);
         ListNode *t1,*t2;
        while(head and mid)
        {
            t1=head->next;
            t2=mid->next;
            head->next=mid;
            mid->next=t1;
            head=t1;
            mid=t2;
        }
       
        if(head and head->next)
        {
            head->next->next=NULL;
        }
        
    }
};