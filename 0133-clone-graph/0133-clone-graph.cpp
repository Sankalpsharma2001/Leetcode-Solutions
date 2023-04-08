/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node *node,map<Node*,Node*> &adj)
    {
        vector<Node*>neighbour;
        Node *clone=new Node(node->val);
        adj[node]=clone;
        for(auto &it:node->neighbors)
        {
            if(adj.find(it)!=adj.end())
            {
                neighbour.push_back(adj[it]);
            }
            else
            {
                neighbour.push_back(dfs(it,adj));
            }
        }
        clone->neighbors=neighbour;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        map<Node*,Node*> adj;
        if(node->neighbors.size()==0)
        {
            return new Node(node->val);
        }
        return dfs(node,adj);
    }
};