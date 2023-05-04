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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        int c=0;
        while(c<k)
        {
            if(!temp)
                return head;
            temp=temp->next;
            c++;
        }
        c=k;
        ListNode *cur=head,*prev=NULL,*nxt=NULL;
        while(cur && c--)
        {
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            
        }
        if(cur)
        {
            head->next=reverseKGroup(cur,k);
        }
        return prev;
    }
};