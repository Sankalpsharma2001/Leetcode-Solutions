class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string str="";
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
              reverse(str.begin(),str.end());
                ans+=str;
                ans+=s[i];
                str="";
            }
            else
            {
                str+=s[i];
            }
        }
         reverse(str.begin(),str.end());
                ans+=str;
        return ans;
    }
};