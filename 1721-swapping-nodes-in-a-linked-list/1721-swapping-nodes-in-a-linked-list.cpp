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
    int count(ListNode *head)
    {
        int c=0;
        while(head)
        {head=head->next;
            c++;
        }
        return c;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *cur=head,*pre=NULL;
        int size=count(head);
        int c=1;
        while(c<k)
        {
            pre=cur;
            cur=cur->next;
            c++;
        }
        ListNode *f=cur;
       int x=size-k+1;
        c=1;
        cur=head;
        ListNode *pre1=NULL;
        while(c<x)
        {
            pre1=cur;
             cur=cur->next;
            c++;
        }
        int v=f->val;
        f->val=cur->val;
        cur->val=v;
        return head;
        
    }
};