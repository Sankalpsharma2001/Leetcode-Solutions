//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
    Node *rev(Node *head,int k)
    {
        Node *cur=head,*pre=NULL;
        while(cur && k-->0)
        {
            Node *next=cur->next;
            cur->next=pre;
            // cout<<cur->data<<" ";
            pre=cur;
            cur=next;
        }
        // cout<<pre->data<<" ";
        return pre;
    }
    Node *reverse(Node *head, int k)
    {
        // code here
        int n=0;
        Node *x=head;
        while(x)
        {
            x=x->next;
            n++;
        }
        Node *temp=head;
        Node *cur=head;
        int c=k;
        while(c--)
        {
            cur=cur->next;
        }
       Node *t=rev(head,k);
    //   cout<<t->data<<" ";
       Node *t1=rev(cur,n-k);
    //   cout<<cur->data<<" "<<t->data<<" "<<t1->data<<endl;
       temp->next=t1;
       return t;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends