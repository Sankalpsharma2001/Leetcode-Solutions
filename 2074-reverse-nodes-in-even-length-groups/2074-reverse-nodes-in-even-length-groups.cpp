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
        if(!head)
            return head;
        ListNode *cur=head,*prev=NULL;
        while(cur)
        {
            ListNode *nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
         if(!head)
            return head;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *prev=dummy;
        for(int len=1;len<1e5 && head;len++)
        {
            ListNode *tail=head;
            int j=1;
            while(j<len && tail && tail->next)
            {
                tail=tail->next;
                j++;
            }
            ListNode *nextNode=tail->next;
            if(j%2==0)
            {
                tail->next=NULL;
                prev->next=reverse(head);
                prev=head;
                head->next=nextNode;
                head=nextNode;
            }
            else
            {
                prev=tail;
                head=nextNode;
            }
        }
        return dummy->next;
    }
};