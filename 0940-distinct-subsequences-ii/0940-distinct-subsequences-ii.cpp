class Solution {
public:
    int mod=1e9+7;
    int solve(string &s,int i,vector<int> &dp)
    {
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        vector<int> vis(26,0);
        int ans=0;
        for(int j=i;j<s.size();j++)
        {
            if(vis[s[j]-'a']) continue;
            vis[s[j]-'a']=1;
                   ans=(ans+1+solve(s,j+1,dp))%mod;
        }
      return dp[i]=ans;
    }
    int distinctSubseqII(string s) {
      int n=s.size();
        vector<int> dp(n,-1);
        return solve(s,0,dp);
    }
};