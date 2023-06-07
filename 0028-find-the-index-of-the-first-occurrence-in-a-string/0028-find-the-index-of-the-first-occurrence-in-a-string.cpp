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
    int strStr(string haystack, string needle) {
         string s=needle+'$'+haystack;
  vector<int> z=calculateZ(s);
  vector<int> ans;
  for(int i=0;i<z.size();i++)
  {
    if(z[i]==needle.size())
    {
      return i-needle.size()-1  ;
    }
  }
        return -1;
    }
};