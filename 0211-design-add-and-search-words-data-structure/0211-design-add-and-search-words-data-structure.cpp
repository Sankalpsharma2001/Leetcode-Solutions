 class Node{
        public:
        Node *child[26];
        bool isEnd=false;
         bool contain(char c)
        {
          return child[c-'a']!=NULL;
        }
         void add(char c,Node *t)
       {
        child[c-'a']=t;
       }
          Node *get(char c)
         {
         return child[c-'a'];
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
class WordDictionary {
public:
   Node *root;
    WordDictionary() {
        root=new Node();
    }
    bool find(int i,string word,Node *root)
    {
        if(i==word.size())
            return root->getEnd();
        char c=word[i];
        if(c!='.')
        {
            return root->get(word[i]) && find(i+1,word,root->get(word[i]));
        }
        else
        {
            for(int cnt=0;cnt<26;cnt++)
            {
                if(root->get(cnt+'a') && find(i+1,word,root->get(cnt+'a')))
                    return true;
            }
            return false;
        }
        
    }
    void addWord(string word) {
        Node *t=root;
        for(char &c:word)
        {
            if(!t->contain(c))
            {
                t->add(c,new Node());
            }
            t=t->get(c);
        }
        t->setEnd();
    }
    
    bool search(string word) {
        return find(0,word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */