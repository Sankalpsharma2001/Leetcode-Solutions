class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
         ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      int n=grid.size();
        int m=grid[0].size();
vector<vector<vector<int>>> dp(n+2,vector<vector<int>>(m+2,vector<int>(m+2,0)));
      for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2)
                {
                    dp[n-1][j1][j2]=grid[n-1][j1];
                    
                }
                else
                    dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
                
                    
            }
        }
        int dy[3]={-1,0,1};
        for(int i=n-2;i>=0;i--)
    {
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                int temp=-1e7;
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        int x=0;
                        if(j1==j2)
                        {
                            x=grid[i][j1];
                        }
                        else
                            x=grid[i][j1]+grid[i][j2];
            if(j1+dy[k]>=0 and j1+dy[k]<m and j2+dy[l]>=0 and j2+dy[l]<m)
                        x+=dp[i+1][j1+dy[k]][j2+dy[l]];
                        else
                            x+=-1e7;
                        temp=max(temp,x);
                    }
                }
                dp[i][j1][j2]=temp;
            }
        }
    }
    return dp[0][0][m-1];
    }
    
};