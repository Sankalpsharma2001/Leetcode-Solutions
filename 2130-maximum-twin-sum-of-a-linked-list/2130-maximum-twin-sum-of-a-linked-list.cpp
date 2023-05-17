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
    ListNode *reverse(ListNode *head)
    {
        ListNode *cur=head,*prev=NULL;
        while(cur)
        {
          
            ListNode *nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        int c=0;
        ListNode *slow=head,*fast=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        slow=reverse(slow);
        
        int ans=0;
        while(slow)
        {
            ans=max(ans,(head->val+slow->val));
            head=head->next;
            slow=slow->next;
            
        }
        return ans;
    }
};