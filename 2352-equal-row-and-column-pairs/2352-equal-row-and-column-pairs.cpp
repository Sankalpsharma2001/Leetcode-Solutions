
class Node
{
public:
    unordered_map<int,Node*> links;
    int cnt=0;
    bool flag=false;
    bool containkey(int ch)
    {
        return (links[ch] != NULL);
    }
    void put(int ch, Node *node)
    {
        links[ch ] = node;
    }
    Node *get(int ch)
    {
        return links[ch ];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(vector<int> &v)
    {
        Node *node = root;
        for (int i = 0; i < v.size(); i++)
        {
            if (!node->containkey(v[i]))
            {
                node->put(v[i], new Node());
            }
            node = node->get(v[i]);
        }
        node->cnt++;
    }
    int search(vector<int> &v)
    {
        Node *node = root;
        for (int i = 0; i < v.size(); i++)
        {
            if (!node->containkey(v[i]))
                return 0;
            node = node->get(v[i]);
        }
        return node->cnt;
    }
    
    
};
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        Trie t; 
        int ans = 0;
       
        for (int i = 0; i < grid.size(); i++)
        {
            t.insert(grid[i]);
        }
        for (int i = 0; i < grid[0].size(); i++)
        {
            vector<int> v;
            for (int j = 0; j < grid.size(); j++)
                v.push_back(grid[j][i]);
          ans+=t.search(v);
        }
        return ans;
    }
};