class Solution {
public:
   class Trie{
       public:
       Trie *child[26];
       bool isEnd=false;
       Trie()
       {
           for(int i=0;i<26;i++)
               child[i]=NULL;
       }
       void insert(string &s,Trie *root,string &ans)
       {
           string str="";
           Trie *node=root;
           for(int i=0;i<s.size();i++)
           {
               if(i==s.size()-1) str+=s[i];
               if(node->child[s[i]-'a']==NULL)
               {
                   if(i!=s.size()-1) break; 
                   //if the char is not present and it isn't the last char of the word
				//then no need to insert it. EX: {"a","ad","adpf"} we won't be inserting adpf 
				//as there is no "adp"
                   node->child[s[i]-'a']=new Trie();
               }
               else
               {
                   str+=s[i];
               }
               node=node->child[s[i]-'a'];
           }
           if(ans.size()<str.size())
               ans=str;
           else if(ans.size()==str.size() and str<ans)
           {
               ans=str;
           }
           node->isEnd=true;
       }
   };
    string longestWord(vector<string>& words) {
     sort(words.begin(),words.end());
        Trie *root=new Trie();
        
    string ans="";
        for(int i=0;i<words.size();i++)
        {
            // if {a,e,e} is there then ans will store ee not a 
            if(i+1<words.size() && words[i]==words[i+1])continue;
            root->insert(words[i],root,ans);
        }
        return ans;
    }
};