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
     ListNode *mergeLists(ListNode* a,ListNode* b)
    {
        if(!a) return b;
        if(!b) return a;
        if(a->val<b->val)
        {
            a->next=mergeLists(a->next,b);
            return a;
        }
        else
        {
            b->next=mergeLists(a,b->next);
            return b;
        }
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if(lists.size()==0)
            return NULL;
        ListNode *head=lists[0];
        for(int i=1;i<lists.size();i++)
        {
            // head=mergeLists(head,lists[i]);
            head=mergeTwoLists(head,lists[i]);
        }
        return head;
    }
};