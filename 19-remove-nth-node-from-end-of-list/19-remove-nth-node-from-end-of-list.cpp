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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      
ListNode *cur=head,*ans=head;
int l=0;
        while(cur)
        {
            cur=cur->next;
            l++;
        }
        if(l==n) return head->next;
        for(int i=1;i<l-n;i++)
        {
            ans=ans->next;
        }
        ans->next=ans->next->next;
        return head;
    }
};