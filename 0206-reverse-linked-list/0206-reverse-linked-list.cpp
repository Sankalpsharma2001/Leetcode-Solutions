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
    ListNode *rev(ListNode *head,ListNode *pre)
    {
        if(!head)return pre;
        ListNode *nxt=head->next;
        head->next=pre;
        return rev(nxt,head);
    }
    ListNode* reverseList(ListNode* head) {
        return rev(head,NULL);
    }
};