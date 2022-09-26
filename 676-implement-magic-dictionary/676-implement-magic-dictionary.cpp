class MagicDictionary {
public:
   
    class Trie{
        public:
        Trie *child[26];
        bool isEnd;
        Trie()
        {
            isEnd=false;
            for(int i=0;i<26;i++)
                child[i]=NULL;
        }
    };
    Trie *root=new Trie();
    MagicDictionary() {
    
    }
    
    void buildDict(vector<string> dictionary) {
     
        for(string s:dictionary)
        {
        Trie *node=root;      
            for(int i=0;i<s.size();i++)
            {
                if(!node->child[s[i]-'a'])
                {
                    node->child[s[i]-'a']=new Trie();
                }
                node=node->child[s[i]-'a'];
            }
            node->isEnd=true;
        }
    }
    bool check(string s)
    {
        Trie *node=root;
        for(int i=0;i<s.size();i++)
        {
            if(node->child[s[i]-'a']==NULL)
                return false;
            node=node->child[s[i]-'a'];
        }
        return node->isEnd;
    }
    bool search(string searchWord) {
       
        
        string s=searchWord;
        int n=searchWord.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                if('a'+j==searchWord[i])
                    continue;
                s[i]='a'+j;
                if(check(s))
                {
                    return true;
                }
            }
            s[i]=searchWord[i];
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */