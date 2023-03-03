class Solution {
public:
    vector<int> prefix_function(string s)
{
    vector<int> lps(s.size(),0);
    lps[0]=0;
    int len=0,i=1;
    while(i<s.size())
    {
       if(s[i]==s[len])
       {
        lps[i]=len+1;
        len++,i++;
       }
       else
       {
        if(len!=0)
        {
            len=lps[len-1];
        }
        else
        {
            lps[i]=0;
            i++;
        }
       }
    }
        return lps;
} 
    int strStr(string haystack, string needle) {
        
 vector<int> pi=prefix_function(needle);
//         int pos=-1;
//         int i=0,j=0;
//         while(j<haystack.size())
//         {
//             if(haystack[j]==needle[i])
//             {
//                 i++;j++;
//             }
//             else
//             {
//                 if(i!=0)
//                     i=pi[i-1];
//                 else
//                     j++;
//             }
//             if(i==needle.size())
//             {
//                return j-needle.size();
               
//             }
//         }
//         return pos;
         int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            while(j<n){
                if (haystack[i + j] != needle[j]) {
                    break;
                }
                j++;
            }
            if (j == n) {
                return i;
            }
        }
        return -1; 
    }
};