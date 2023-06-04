/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
            Node *cur=head;
        while(cur)
        {
            Node *nxt=cur->next;
            Node* copy=new Node(cur->val);
            cur->next=copy;
            copy->next=nxt;
            cur=nxt;
        }
        
        cur=head;
        while(cur)
        {
            if(cur->random)
            {
                cur->next->random=cur->random->next;
            }
            cur=cur->next->next;
        }
        cur=head;
        Node *ans=new Node(-1);
        Node *res=ans;
        while(cur)
        {
          Node *nxt=cur->next->next;
           res->next=cur->next;
            cur->next=nxt;
            cur=nxt;
            res=res->next;
        }
        return ans->next;
    }
};