class Solution {
public:
    
    int countSubstrings(string s) {
      
       int n=s.size();
        int dp[n][n];
        int start=0,len=0,ans=0;
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;j++,i++)
            {
                if(g==0)
                    dp[i][j]=1;
                if(g==1)
                {
                    if(s[i]==s[j])
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                }
                if(g>1)
                {
                    if(s[i]==s[j] and dp[i+1][j-1]==1)
                        dp[i][j]=1;
                    else
                        dp[i][j]=0;
                    
                }
                  if(dp[i][j])
            {
              ans++;
            }
            }
          
        }
        return ans;
    }
};