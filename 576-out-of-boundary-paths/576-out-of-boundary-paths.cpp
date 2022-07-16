class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int mod=1e9+7;
    int solve(int &n,int &m,int mx,int i,int j,vector<vector<vector<int>>> &dp)
    {
        if(i<0 || j<0 || i==n || j==m )
            return 1;
        
        if(mx==0) return 0;
        if(dp[i][j][mx]!=-1)
            return dp[i][j][mx];
        long long int ans=0;
        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];
            ans+=solve(n,m,mx-1,x,y,dp)%mod;
            
        }
        return dp[i][j][mx]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return solve(m,n,maxMove,startRow,startColumn,dp);
        
    }
};