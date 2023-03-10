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
      ListNode* start;
    Solution(ListNode* head) {
        start=head;
    }
    
    int getRandom() {
        int ans,len=1;
        ListNode *s=start;
        while(s)
        {
            if(rand()%len==0)
            {
                ans=s->val;
            }
            len++;
            s=s->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */