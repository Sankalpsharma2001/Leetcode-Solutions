//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    Node* search(Node* root, int target, int &s){
        if(root==NULL or root->data==target)
            return root;
        s+=root->data;
        if(target<root->data)
            return search(root->left,target,s);
        else
            return search(root->right,target,s);
    }
   void solve(Node *root,int sum,int &ans)
   {
       if(!root->left && !root->right)
       {
           sum+=root->data;
           ans=min(ans,sum);
           return;
           
       }
       if(root->left)
       solve(root->left,sum+root->data,ans);
       if(root->right)
       solve(root->right,sum+root->data,ans);
   }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        
           int a=0,b=INT_MAX;
        Node* t=search(root,target,a);
        // a stores root to target sum
                if(t==NULL)  return -1;
        solve(t,0,b);
        b-=target;
        return a-b;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends