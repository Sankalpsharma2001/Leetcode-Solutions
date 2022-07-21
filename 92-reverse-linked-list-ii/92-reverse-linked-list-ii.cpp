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
    ListNode* reverse(ListNode *head)
    {
        ListNode *cur=head;
        ListNode *pre=NULL;
        while(cur)
        {
            ListNode *nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur-nxt;
        }
        return pre;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head or !head->next)
            return head;
        if(left==right)
            return head;
        ListNode *f=head;
        int c=1;
        ListNode *fpre=NULL;
        while(f and c<left)
        {
            c++;
            fpre=f;
            f=f->next;
        }
        ListNode *cur=f;
        ListNode *pre=fpre;
        for(int i=left;i<=right;i++)
        {
            ListNode *nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        
        }
        if(left==1)
        {
            head=pre;
        }
        if(fpre)
        fpre->next=pre;
        f->next=cur;
        return head;
        
    }
};