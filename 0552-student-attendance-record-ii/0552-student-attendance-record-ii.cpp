class Solution {
public:
    int mod=1e9+7;
    long long countWays(int n,int a,int l)
    {
        
        if(a>=2 || l>=3) return 0;
        if(n==0) return 1;
        if(dp[n][a][l]!=-1) return dp[n][a][l];
        long long ans=0;
        ans=(ans%mod+countWays(n-1,a,0)%mod)%mod; //present
        ans=(ans%mod+countWays(n-1,a+1,0)%mod)%mod; // absent
        ans=(ans%mod+countWays(n-1,a,l+1)%mod)%mod; // absent
        return dp[n][a][l]=ans%mod;
    }
    int dp[100005][2][3];
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return countWays(n,0,0)%mod;
        
    }
};