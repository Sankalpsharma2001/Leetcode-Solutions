class Solution {
public:
    int dp[1001][1001];
    int n,m;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int mod=1e9+7;
    bool isValid(int x,int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || j<0 || i>=n  || j>=m ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
       long long  ans=1;
    
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];
            if(isValid(x,y))
            {
                if(grid[x][y]>grid[i][j])
            ans=(ans%mod+dfs(grid,x,y)%mod)%mod;
            }
        }
        return dp[i][j]=ans%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
       long long int ans=0;
                
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 ans+=(dfs(grid,i,j))%mod;
                
            }
        }
        return ans%mod;
    }
};