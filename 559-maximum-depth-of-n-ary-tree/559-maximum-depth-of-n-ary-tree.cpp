/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        // int depth=0;
        // for(auto child:root->children)
        // {
        //     depth=max(depth,maxDepth(child));
        // }
        // return depth+1;
    queue<Node *> q;
        q.push(root);
        int depth=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                auto f=q.front();
                q.pop();
                for(auto child:f->children)
                {
                    if(child)
                        q.push(child);
                }
                
            }
            depth++;
        }
        return depth;
    }
};