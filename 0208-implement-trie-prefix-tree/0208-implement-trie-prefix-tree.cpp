class Node
{
    public:
    
    Node *children[26];
    bool isEnd=false;
    bool contain(char c)
    {
        return children[c-'a']!=NULL;
    }
    void add(char c,Node *t)
    {
        children[c-'a']=t;
    }
    Node *get(char c)
    {
        return children[c-'a'];
    }
    
    bool getEnd()
    {
        return isEnd;
    }
    void setEnd()
    {
        isEnd=true;
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
            if(!t->contain(word[i]))
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
            if(t->contain(word[i]))
            {
                t=t->get(word[i]);
            }
            else
                return false;
        }
        return t->getEnd();
    }
    
    bool startsWith(string prefix) {
      Node *t=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!t->contain(prefix[i]))
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