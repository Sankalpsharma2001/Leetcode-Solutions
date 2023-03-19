class WordDictionary {
public:
    unordered_map<int,vector<string>> m;
    WordDictionary() {
        m.clear();
    }
    bool check(string &a,string &b)
    {
        for(int i=0;i<a.size();i++)
        {
            if(b[i]=='.') continue;
            if(b[i]!=a[i]) return false;
        }
        return true;
    }
    void addWord(string word) {
        m[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for(auto &it:m[word.size()])
        {
            if(check(it,word))
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */