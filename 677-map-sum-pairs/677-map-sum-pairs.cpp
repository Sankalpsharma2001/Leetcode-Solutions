class MapSum {
public:
    class Trie{
        public:
        Trie *child[26];
        bool isEnd;
        int value;
        Trie()
        {
            for(int i=0;i<26;i++)
                child[i]=NULL;
            isEnd=false;
            value=0;
        }
    };
    Trie *root=new Trie();
    unordered_map<string,int> m;
    MapSum() {
        m.clear();
    }
    
    void insert(string key, int val) {
      Trie *node=root;
        int old=val-m[key];
            
        for(int i=0;i<key.size();i++)
        {
            int x=key[i]-'a';
            if(node->child[x]==NULL)
            {
                node->value+=old;
                node->child[x]=new Trie();
               
            }
            else
            {
                node->value+=old;
            }
            node=node->child[x];
        }
        node->value+=old;
        m[key]=val;
    }
    
    int sum(string prefix) {
         Trie *node=root;
        for(int i=0;i<prefix.size();i++)
        {
         int x=prefix[i]-'a';
            if(node->child[x]==NULL)
                return 0;
            node=node->child[x];
        }
        return node->value;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */