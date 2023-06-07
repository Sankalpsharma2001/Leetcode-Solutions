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
    string longestPrefix(string s) {
        
  vector<int> z=calculateZ(s);
      int mx=0;
        for(int i=0;i<s.size();i++)
        {
            if(z[i]==s.size()-i)
            {
                mx=max(mx,(int)s.size()-i);
            }
        }
        return s.substr(0,mx);
    }
};