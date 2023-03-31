class Solution {
public:
    int mod=1e9+7;
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<long > dp(n+1,0);
        dp[0]=1;
        unordered_map<char,int> m;
        for(int i=1;i<dp.size();i++)
        {
            char ch=s[i-1];
              dp[i]=((2)*(dp[i-1]))%mod;
            if(m.find(ch)!=m.end())
            {
                int j=m[ch];
                dp[i]=(dp[i]-dp[j-1])%mod;
            }
           m[ch]=i;
            
        }
        if(dp[n]<=0) dp[n]+=mod;
        return dp[n]-1;
    }
};