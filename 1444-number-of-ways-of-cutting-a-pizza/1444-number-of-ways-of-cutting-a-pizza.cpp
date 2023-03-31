class Solution {
public:
    int mod=1e9+7;
    int solve(vector<string>& pizza, int k,int r,int c,int &n,int &m,vector<vector<int>> &preSum,vector<vector<vector<int>>> &dp)
    {
        if(preSum[r][c]==0) return 0;
        if(k==0) return 1;
        if(dp[k][r][c]!=-1) return dp[k][r][c];
        int ans=0;
        
        for(int nr=r+1;nr<n;nr++)
        {
            if(preSum[r][c]-preSum[nr][c]>0)
            {
                ans=(ans+solve(pizza,k-1,nr,c,n,m,preSum,dp))%mod;
            }
            
        }
        for(int nc=c+1;nc<m;nc++)
        {
            if(preSum[r][c]-preSum[r][nc]>0)
            {
                ans=(ans+solve(pizza,k-1,r,nc,n,m,preSum,dp))%mod;
            }
        }
        return dp[k][r][c]=ans;
    }
    int ways(vector<string>& pizza, int k) {
        int n=pizza.size();
        int m=pizza[0].size();
        vector<vector<vector<int>>> dp(k,vector<vector<int>> (n,vector<int>(m,-1)));
        vector<vector<int>> preSum(n+1,vector<int>(m+1,0));
        for(int r=n-1;r>=0;r--)
        {
            for(int c=m-1;c>=0;c--)
            {
                preSum[r][c]=preSum[r+1][c]+preSum[r][c+1]-preSum[r+1][c+1]+(pizza[r][c]=='A');
            }
        }
        return solve(pizza,k-1,0,0,n,m,preSum,dp);
        
    }
};