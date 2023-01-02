class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag=true;
        if(word[0]>='A' && word[0]<='Z')
        {
            flag=true;
        }
        else
        {
            flag=false;
        }
        if(word[1]>='a' && word[1]<='z') flag=false;
        
        
        for(int i=1;i<word.size();i++)
       {
         if(word[i]>='a' && word[i]<='z' && flag )
         {
             return false;
         }
          if(word[i]>='A' && word[i]<='Z' && flag==false)  
          {
              return false;
          }
       }
        return true;
    }
};