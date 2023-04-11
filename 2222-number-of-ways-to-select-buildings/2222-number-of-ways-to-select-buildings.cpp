class Solution {
public:
    long long numberOfWays(string s) {
        int n=s.size();
        vector<int> pre(n,0),suf(n,0),pre1(n,0),suf1(n,0);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(i)
                pre[i]=pre[i-1]+1;
                else
                pre[i]=1;
            }
            else
            {
                if(i)
                pre[i]=pre[i-1];
            }
            
            if(s[i]=='1')
            {
              if(i)
                pre1[i]=pre1[i-1]+1;
                else
                pre1[i]=1;   
            }
            else
            {
                
                if(i)
                pre1[i]=pre1[i-1];
            }
        }
        
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                if(i!=n-1)
                    suf[i]=suf[i+1]+1;
                else
                    suf[i]=1;
            }
            else
            {
                if(i!=n-1)
                suf[i]=suf[i+1];
            }
            
             if(s[i]=='1')
            {
                if(i!=n-1)
                    suf1[i]=suf1[i+1]+1;
                else
                    suf1[i]=1;
            }
            else
            {
                if(i!=n-1)
                suf1[i]=suf1[i+1];
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                int l=0,r=0;
                if(i>0)
                {
                    l=pre1[i];
                }
                if(r<n-1)
                {
                    r=suf1[i];
                }
                ans+=(l*r);
            }
            else
            {
                int l=0,r=0;
                if(i>0)
                {
                    l=pre[i];
                }
                if(r<n-1)
                {
                    r=suf[i];
                }
                ans+=(l*r);
                
                
            }
        }
        return ans;
    }
};