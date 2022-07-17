class Solution {
public:
     int mod=1e9+7;
    // int solve(int n,int k,vector<vector<int>> &dp)
    // {
    //     if(n==0) return 0;
    //     if(k<0) return 0;
    //     if(k==0)
    //         return 1;
    //   if(dp[n][k]==0)
    //   {
    //     for(int i=0;i<n;i++)
    //     {
    //         dp[n][k]+=solve(n-1,k-i,dp)%mod;
    //     }
    //   }
    //     return dp[n][k];
    // }
    // int kInversePairs(int n, int k) {
    //    // vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    //     int dp[1001][1001]={1};
    //    // return solve(n,k,dp);
    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=0;j<=k;j++)
    //         {
    //             if(j==0)
    //             {
    //                 dp[i][j]=1;
    //                 continue;
    //             }
    //             else
    //             {
    //                 for(int l=0;l<=min(i-1,j);l++)
    //                 {
    //                     dp[i][j]=(dp[i][j]+dp[i-1][j-l])%mod;
    //                 }
    //             }
    //         }
    //     }
    //     return dp[n][k];
    // }
      int dp[1001][1001] = {};
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = { 1 };
        for (int N = 1; N <= n; ++N)
            for (int K = 0; K <= k; ++K)
                for (int i = 0; i <= min(K, N - 1); ++i) 
                    dp[N][K] = (dp[N][K] + dp[N - 1][K - i]) % 1000000007;
        return dp[n][k];
}
     
};