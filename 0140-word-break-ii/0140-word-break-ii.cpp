class Node
{
public:
    Node *links[26];
    bool flag = false;
    bool containkey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
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
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containkey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containkey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

};
class Solution {
public:
    vector<string > ans;
    void solve(string s,vector<string> &word,string v,int idx,Trie &t)
    {  if(idx==s.size())
    {
        v.pop_back(); // pop out last space
        ans.push_back(v);
        return;
    }
        for(int i=idx;i<s.size();i++)
        {
            string str=s.substr(idx,i-idx+1);
            if(t.search(str))
                solve(s,word,v+str+' ',i+1,t);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie t;
        for(auto &x:wordDict)
        {
            t.insert(x);
        }
        
        solve(s,wordDict,"",0,t);
        return ans;
    }
};