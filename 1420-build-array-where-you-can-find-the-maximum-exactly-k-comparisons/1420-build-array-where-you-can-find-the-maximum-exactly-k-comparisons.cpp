class Solution {
public:
    int mod=1e9+7;
    int solve(int i,int n,int m,int k,vector<vector<vector<int>>> &dp)
    {
        if(n<=0)
        {
            return k==0;
        }
        if(dp[i][n][k]!=-1) return dp[i][n][k];
        int ans=0;
        for(int j=1;j<=m;j++)
        {
            if(j>i)
            {
                if(k>0)
                {
                  ans=(ans%mod+solve(j,n-1,m,k-1,dp)%mod)%mod;  
                }
                    
            }
            else
            {
                ans=(ans%mod+solve(i,n-1,m,k,dp)%mod)%mod;
            }
        }
        return dp[i][n][k]=ans;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return solve(0,n,m,k,dp);
        
    }
};