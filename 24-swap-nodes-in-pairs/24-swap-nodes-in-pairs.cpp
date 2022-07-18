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
    ListNode* swapPairs(ListNode* head) {
      if(!head)
          return NULL;
        if(!head->next)
            return head;
     
        ListNode *ans=new ListNode(0),*t=ans;
        ans->next=head;
        while(head and head->next)
        {
            ListNode *nex=head->next;
            head->next=nex->next;
            nex->next=head;
            t->next=nex;
            t=head;
            head=t->next;
        }
        return ans->next;
     
    }
};