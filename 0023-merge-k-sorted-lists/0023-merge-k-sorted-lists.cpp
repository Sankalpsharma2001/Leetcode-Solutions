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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         if(lists.size()==0)
            return NULL;
        ListNode *head=lists[0];
        for(int i=1;i<lists.size();i++)
        {
            head=mergeLists(head,lists[i]);
        }
        return head;
    }
};