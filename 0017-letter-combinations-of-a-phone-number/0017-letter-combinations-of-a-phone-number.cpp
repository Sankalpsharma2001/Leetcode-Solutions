class Solution {
public:
    vector<string> ans;
     string keyPad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    void backtrack(int idx,string res,string digits)
    { 
        if(idx==digits.size())
        {ans.push_back(res);
        return;}
        for(char c:keyPad[digits[idx]-'0'])
        {
            res[idx]=c;
            backtrack(idx+1,res,digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        string res=digits;
        if(digits.size()==0)
        return ans;
       backtrack(0,res,digits);
        return ans;
        /* map<int,string> m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        vector<string> ans;
      if(digits.size()==1)
      { char a=digits[0];
          for(auto it:m[a-'0'])
          { string s="";
           s=it;
           ans.push_back(s);   
          }
      }
        else if(digits.size()==2)
        {
            char a=digits[0];
         
          char b=digits[1];
            for(auto it:m[a-'0'])
            { auto s=it;
             string d="";
             d=s;
                 for(auto p:m[b-'0'])
                 {
                     ans.push_back(d+p);
                 }
            
                  }
            
        }
        
        else if(digits.size()==3)
        {
            
            char a=digits[0];
         
          char b=digits[1];
            char c=digits[2];
            for(auto it:m[a-'0'])
            { auto s=it;
             string d="";
             d=s;
                 for(auto p:m[b-'0'])
                 { string e="";
                  e=p;
                     for(auto q:m[c-'0'])
                     ans.push_back(d+e+q);
                 }
            
                  }
        }
        else if(digits.size()==4)
        {
            
            char a=digits[0];
         
          char b=digits[1];
            char c=digits[2];
            char d=digits[3];
            for(auto it:m[a-'0'])
            { auto s=it;
             string t="";
             t=s;
                 for(auto p:m[b-'0'])
                 { string e="";
                  e=p;
                     for(auto q:m[c-'0'])
                     {string v="";
                      v=q;
                         for(auto w:m[d-'0'])
                     ans.push_back(t+e+v+w);
                     }
                 }
            
                  }
        }
            return ans;*/
    }
};