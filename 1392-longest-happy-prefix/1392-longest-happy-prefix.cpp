class Solution {
public:
    

vector<int> calculateZ(string &s)
{
    int n = s.size();
    vector<int> z(n);
    z[0] = 0;
   int left=0,right=0;
    for(int k=1;k<s.size();k++)
    {
      if(k>right)
      {
        left=right=k;
        while(right<s.size() && s[right]==s[right-left])
        {
          right++;
        }
        z[k]=right-left;
        right--;
      }
      else
      {
        // we are operating inside box 
        int k1=k-left;
        // if value does not stretches till right bound then just copy it 
        if(z[k1]<right-k+1)
        {
          z[k]=z[k1];
        }
        else
        {
          left=k;
          while(right<s.size() && s[right]==s[right-left])
          {right++;
          }
          z[k]=right-left;
          right--;
        }
      } 
    } 
    return z;   

}
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
    string longestPrefix(string s) {
        
  // vector<int> z=calculateZ(s);
      // int mx=0;
      //   for(int i=0;i<s.size();i++)
      //   {
      //       if(z[i]==s.size()-i)
      //       {
      //           mx=max(mx,(int)s.size()-i);
      //       }
      //   }
        vector<int> pre=prefix_function(s);
        int mx=pre[s.size()-1];
        return s.substr(0,mx);
    }
};