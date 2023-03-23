class Solution {
public:
    int dp[5001][4][4][4];
    int mod=1e9+7;
    int dfs(int n,int apre,int bpre,int cpre)
    {
        if(n==0) return 1;
        if(dp[n][apre][bpre][cpre]!=-1)
            return dp[n][apre][bpre][cpre]%mod;
        vector<int> color{1,2,3};
        int ans=0;
        for(int &a:color)
        {
            if(a==apre) continue;
            for(int &b:color)
            {
                if(b==bpre || b==a) continue;
                for(int &c:color)
                {
                    if(c==cpre || c==b) continue;
                    ans+=dfs(n-1,a,b,c)%mod;
                    ans%=mod;
                }
            }
        }
        return dp[n][apre][bpre][cpre]=ans%mod;
    }
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
       return dfs(n,0,0,0);
        
        
    }
};