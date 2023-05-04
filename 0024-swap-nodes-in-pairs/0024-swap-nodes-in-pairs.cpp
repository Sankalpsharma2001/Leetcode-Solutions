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
//           recursion
//         if(!head || !head->next)
//             return head;
//         ListNode *t=head->next;
//         head->next=swapPairs(t->next);
//         t->next=head;
//         return t;
        
        // iterative
        if(!head || !head->next)
            return head;
        ListNode *ans=new ListNode(-1);
        ListNode *cur=head,*prev=ans;
         
        while(cur && cur->next)
        {
           
            prev->next=cur->next;
            cur->next=prev->next->next;
            prev->next->next=cur;
            prev=cur;
            cur=cur->next;
            
            
        }
        return ans->next;
        
    }
};