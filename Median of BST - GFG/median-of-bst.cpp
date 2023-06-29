//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST

int counNodes(Node *root)
{
   
    Node *cur=root;
    int cnt=0;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            cnt++;
           
            cur=cur->right;
        }
        else
        {
            Node *pre=cur->left;
            while(pre->right and pre->right!=cur)
            pre=pre->right;
            if(pre->right==NULL)
            {
                pre->right=cur;
                cur=cur->left;
            }
            else
            {
                pre->right=NULL;
                cnt++;
                cur=cur->right;
            }
        }
    }
   return cnt;
}
float findMedian(struct Node *root)
{
      //Code here
        if (root == NULL)
        return 0;
 
    int count = counNodes(root);
    int currCount = 0;
     Node *current = root, *pre, *prev;
      while (current != NULL)
    {
        if (current->left == NULL)
        {
            // count current node
            currCount++;
 
            // check if current node is the median
            // Odd case
            if (count % 2 != 0 && currCount == (count+1)/2)
                return current->data;
 
            // Even case
            else if (count % 2 == 0 && currCount == (count/2)+1)
                return (float)(prev->data + current->data)/2.0;
 
            // Update prev for even no. of nodes
            prev = current;
 
            //Move to the right
            current = current->right;
        }
        else
        {
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
 
            /* Make current as right child of its inorder predecessor */
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in if part to restore the original
              tree i.e., fix the right child of predecessor */
            else
            {
                pre->right = NULL;
 
                prev = pre;
 
                // Count current node
                currCount++;
 
                // Check if the current node is the median
                if (count % 2 != 0 && currCount == (count+1)/2 )
                    return current->data;
 
                else if (count%2==0 && currCount == (count/2)+1)
                    return (float)(prev->data+current->data)/2.0;
 
                // update prev node for the case of even
                // no. of nodes
                prev = current;
                current = current->right;
 
            }
        } 
    } 
    return 0;
}

