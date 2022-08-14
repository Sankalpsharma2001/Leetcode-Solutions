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
        ListNode *x=head;
        int c=0;
        while(c<k)
        {
            if(!x)
                return head;
            x=x->next;
            c++;
        }
        c=k;
        ListNode *cur=head;
        ListNode *pre=NULL,*nxt=NULL;
        while(cur and c--)
        {
            nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        if(nxt)
            head->next=reverseKGroup(nxt,k);
        return pre;
    }
};