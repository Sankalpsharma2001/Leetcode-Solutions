class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         unordered_set<string> dict;
        for(auto &x:wordList)
        {
            dict.insert(x);
        }
      if(dict.find(endWord)==dict.end())
             return 0;
        queue<string> q;
        q.push(beginWord);
        int ans=1;
       while(!q.empty())
       {
           int sz=q.size();
           while(sz--)
           {
               string f=q.front();
               q.pop();
               if(f==endWord)
                   return ans;
                dict.erase(f);
               for(int i=0;i<f.size();i++)
               {
                   char c=f[i];
                     for(int j=0;j<26;j++)
                 {
                     f[i]='a'+j;
                     if(dict.find(f)!=dict.end())
                     {
                         q.push(f);
                     }
                 }
                   f[i]=c;
               }
           }
           ans++;
       }
        return 0;
    }
};