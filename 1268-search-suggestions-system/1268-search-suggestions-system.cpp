class Solution {
public:
     struct Trie {
        unordered_map<char, Trie*> leaves;
        // Lexographically sorted suggestion till each char 
        vector<string> suggestions;
    };
    
    void insertTrie(Trie* root, string word) {
        for(const char& c: word) {
            if(root->leaves.find(c) == root->leaves.end())
                root->leaves[c] = new Trie();
            root = root->leaves[c];
            
            // Add the current word as suggestion if we dont have enough suggestions
            if(root->suggestions.size() < 3)
                root->suggestions.push_back(word);
        }
    }
    
    
    vector<vector<string>> suggestionTrie(vector<string>& products, string searchWord) {
        vector<vector<string>> result(searchWord.size());
        // sort the words 
        sort(begin(products), end(products));
        // Create the Trie, since the words are sorted
        // so the suggestions are also lexographically sorted
        Trie *root = new Trie();
        for( string &word: products)
            insertTrie(root, word);
        
        string prefix;
        for(int i = 0; i < searchWord.size(); i++) {
            auto it = root->leaves.find(searchWord[i]);
            if(it != root->leaves.end()) {
                root = it->second;
            }
            else
                break;
            // add suggestions if any for the current char
            result[i] = root->suggestions;
        }
        return result;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)    {
        return suggestionTrie(products, searchWord);
    }
};