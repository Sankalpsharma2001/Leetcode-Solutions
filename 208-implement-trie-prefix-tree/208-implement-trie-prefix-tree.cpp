class Node{
    public:
    Node *links[26];
    bool isEnd=false;
    bool contains(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void add(char ch,Node *node)
    {
        links[ch-'a']=node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        isEnd=true;
    }
    bool getEnd()
    {
        return isEnd;
    }
};
class Trie {
public:
    Node *root;
    
    Trie() {
      root=new Node();    
    }
    
    void insert(string word) {
        Node *t=root;
        for(int i=0;i<word.size();i++)
        {
            if(!t->contains(word[i]))
            {
                t->add(word[i],new Node());
            }
            t=t->get(word[i]);
        }
        t->setEnd();
    }
    
    
    bool search(string word) {
         Node *t=root;
        for(int i=0;i<word.size();i++)
        {
            if(!t->contains(word[i]))
            {
                return false;
            }
            t=t->get(word[i]);
        }
        return t->getEnd();
    }
    
    bool startsWith(string prefix) {
         Node *t=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!t->contains(prefix[i]))
            {
                return false;
            }
            t=t->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */