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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1=0,c2=0;
        ListNode *t1=headA,*t2=headB;
        while(t1)
        {
            c1++;
            t1=t1->next;
        }
        while(t2)
        {
            c2++;
            t2=t2->next;
        }
        if(c1<c2)
        {swap(headA,headB);
         swap(c1,c2); 
        }
        int x=c1-c2;
        
        while(x--)
        {
            headA=headA->next;
        }
        while(headA and headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};