class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int i=0,j=0;
        while(i<min(word1.size(),word2.size()))
        {
            ans+=word1[i];
            ans+=word2[i];
            i++;
        }
        if(word1.size()>word2.size())
        {
          while(i<word1.size())
          {
              ans+=word1[i++];
          }
            return ans;
        }
         while(i<word2.size())
          {
              ans+=word2[i++];
          }
            return ans;
        
    }
};