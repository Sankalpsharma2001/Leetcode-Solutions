class Solution {
public:
     class Trie{
      public:
        Trie *child[26];
        bool isEnd = false;
    };
    
    void insert(string &s,Trie *root)
    {
        Trie *node=root;
        for(auto &ch:s)
        {
            if(!node->child[ch-'a'])
            {
                node->child[ch-'a']=new Trie();
            }
            node=node->child[ch-'a'];
        }
        node->isEnd=true;
    }
    bool search(string &s,Trie *root)
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
    int dp[320];
    bool solve(string s,Trie *root,int idx,int n)
    {
        if(idx==n)
            return true;
        if(dp[idx]!=-1)
            return dp[idx];
        for(int i=idx;i<n;i++)
        {
            string str=s.substr(idx,i-idx+1);
            if(search(str,root))
            {
                if(solve(s,root,i+1,n))
                    return dp[idx]=true;
            }
            
        }
        return dp[idx]=false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
       
        Trie *root=new Trie();
        for(auto &s:wordDict)
        {
            insert(s,root);
        }    
        
         memset(dp,-1,sizeof(dp));
        return solve(s,root,0,s.size());
        
        }
};