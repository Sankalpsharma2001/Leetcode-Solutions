class Solution {
public:
    class Node{
    public:
    Node *links[2];
    bool contains(int bit)
    {
        return links[bit]!=NULL;
    }
    void put(int bit,Node *node)
    {
        links[bit]=node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
};
class Trie{
    Node *root;
    public:
    Trie()
    {
        root=new Node();
        
    }
    void insert(int &num)
    {
        Node *node=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!node->contains(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int find(int &num)
    {
        Node *node=root;
        int mx=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(node->contains(1-bit))
            {
                mx=mx|(1<<i);
                node=node->get(1-bit);
            }
            else
                node=node->get(bit);
            
        }
        return mx;
    }
};
    int findMaximumXOR(vector<int>& nums) {
         Trie trie;
    for(int i=0;i<nums.size();i++)
    {
        trie.insert(nums[i]);
    }
    int ans=0;
        for(int i=0;i<nums.size();i++)
    {
        ans=max(ans,trie.find(nums[i]));
    }
    return ans;
    }
};