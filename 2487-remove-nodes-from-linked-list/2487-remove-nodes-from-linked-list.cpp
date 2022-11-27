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
    ListNode* removeNodes(ListNode* head) {
       vector<int> v;
        while(head)
        {
            while(v.size() && v.back()<head->val) v.pop_back();
            v.push_back(head->val);
            head=head->next;
        }
        ListNode *ans=new ListNode(-1),*cur=ans;
        for(auto &x:v)
        {
            cur->next=new ListNode(x);
            cur=cur->next;
        }
        return ans->next;
    }
};