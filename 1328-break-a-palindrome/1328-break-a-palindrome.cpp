class Solution {
public:
    bool check(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return true;
            i++;
            j--;
        }
        return false;
    }
    string breakPalindrome(string palindrome) {
     string ans="";
        int n=palindrome.size();
        for(int i=0;i<n;i++)
        {
            char c=palindrome[i];
            for(int j=0;j<26;j++)
            {
                palindrome[i]='a'+j;
                if(check(palindrome))
                   {
                    if(ans.size()==0 || ans>palindrome)
                    {
                        ans=palindrome;
                    }
                   }
            }
            palindrome[i]=c;
        }
        return ans;
        
        
    }
};