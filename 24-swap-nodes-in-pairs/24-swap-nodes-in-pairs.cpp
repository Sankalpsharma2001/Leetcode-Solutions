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
           ListNode *temp=head->next;       
            head->next=swapPairs(temp->next);
        temp->next=head;
        return temp;
//         ListNode *cur=head;
//         ListNode *pre=NULL;
//         if(head->next) head=head->next;
//         while(cur and cur->next)
//         {
//             ListNode *nex=cur->next;
//             if(pre)
//                 pre->next=nex;
//             pre=nex;
//             cur->next=nex->next;
//             nex->next=cur;
            
//             cur=cur->next;
//         }
//         return head;
    }
};