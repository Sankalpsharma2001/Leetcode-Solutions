
class Node{
    public:
    Node *child[26];
    bool flag;
    Node()
    {
        flag=false;
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
    }
    
};
class Trie{
    private:Node *root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(string s)
    {
        Node *cur=root;
        for(int i=0;i<s.size();i++)
        {
            int idx=s[i]-'a';
            if(cur->child[idx]==NULL)
            {
                cur->child[idx]=new Node();
            }
            cur=cur->child[idx];
        }
        cur->flag=true;
    }
    bool search(string s)
    {
        Node *cur=root;
        for(int i=0;i<s.size();i++)
        {
            int idx=s[i]-'a';
            if(cur->child[idx])
            {
                cur=cur->child[idx];
            }
            else
            return false;
        }
        return cur->flag;
    }
};
class Solution {
public:
    int dp[305];
    bool wordBreaks(string &s,Trie t,int start)
    { 
      int n=s.size();
      if(n==start) return true;
        if(dp[start]!=-1) return dp[start];
      for(int i=start;i<n;i++)
      {
          if(t.search(s.substr(start,i-start+1)) && wordBreaks(s,t,i+1))
          return dp[start]=true;
      }
      return dp[start]=false;
    }
    bool wordBreak(string &s, vector<string>& wordDict) {
         Trie t;
        for(string &s:wordDict)
        {
            t.insert(s);
        }
        memset(dp,-1,sizeof(dp));
        return wordBreaks(s,t,0);
    }
};