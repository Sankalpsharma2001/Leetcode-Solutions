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
    vector<ListNode*>  splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);
        int len=0;
        ListNode *temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        int oneList=len/k;
        int rem=len%k;
        temp=head;
        int i=0;
        while(temp)
        {
            ans[i]=temp;
            int c=1;
            
            while(c<oneList)
            {
                c++;
                temp=temp->next;
            }
            if(rem>0 && len>k)
            {
                 temp=temp->next;
                 rem--;
            }
            ListNode *nxt=temp->next;
            temp->next=NULL;
            temp=nxt;
            i++;
        }
  // for(int i=0;i<ans.size();i++)
  // {
  //     ListNode *t=ans[i];
  //     while(t)
  //     {
  //         cout<<t->val<<" ";
  //         t=t->next;
  //     }
  //     cout<<endl;
  // }
      return ans;

    }
};