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
    ListNode* reverse(ListNode *t)
    {
        ListNode *cur=t,*pre=NULL;
        while(cur)
        {
            ListNode *nex=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nex;
        }
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *a=reverse(l1);
        ListNode *b=reverse(l2);
        int carry=0;
        ListNode *ans=new ListNode(-1);
        ListNode *t=ans;
        int s=0,c=0;
        while(a && b)
        { s=(a->val+b->val)+c;
            t->next=new ListNode(s%10);
          t=t->next;
         c=s/10;
         a=a->next;
         b=b->next;
        }
        while(a)
        {
            s=a->val+c;
              t->next=new ListNode(s%10);
          t=t->next;
            c=s/10;
         a=a->next;
        }
         while(b)
        {
            s=b->val+c;
              t->next=new ListNode(s%10);
          t=t->next;
            c=s/10;
         b=b->next;
        }
        if(c)
              t->next=new ListNode(c);
        return reverse(ans->next);
    }
};