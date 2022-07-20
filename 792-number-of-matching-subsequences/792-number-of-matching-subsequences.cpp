class Solution {
public:
    bool check(string &a,string &b)
    {
        int i=0,j=0;
        while(i<a.size() and j<b.size())
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        return (j==b.size());
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        int n=words.size();
    unordered_map<string,int> m;
        for(auto &x:words)
            m[x]++;
          for(auto &x:m)
          {
             string y=x.first;
              if(check(s,y))
              {
                  ans+=x.second;
              }
             
          }
        return ans;
        
    }
};