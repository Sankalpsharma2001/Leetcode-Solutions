class Solution {
public:
    int findPaths(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=findPaths(i+1,j,m,n,dp)+findPaths(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return findPaths(0,0,m,n,dp);
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=1;
                    continue;
                }
                int up=0;
                int left=0;
                if(i-1>=0)
                 up=dp[i-1][j];
                if(j-1>=0)
                 left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
    }
};