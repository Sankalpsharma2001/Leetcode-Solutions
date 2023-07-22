class Solution {
public:
    bool isvalid(int &x,int &y,int &n)
    {
        if(x>=0 and y>=0 and x<n and y<n)
            return true;
        return false;
    }
    double solve(int &n,int k,int r,int c,vector<vector<vector<double>>> &dp)
    {
        if(!isvalid(r,c,n)) return 0;
        if(k==0) return 1;
        if(dp[r][c][k]!=-1) return dp[r][c][k];
        int dx[]={2,2,-2,-2,1,1,-1,-1};
        int dy[]={1,-1,1,-1,2,-2,2,-2};
        double t=0;
        for(int i=0;i<8;i++)
        {
            int x=r+dx[i];
            int y=c+dy[i];
            t+=(0.125*solve(n,k-1,x,y,dp));
        }
        return dp[r][c][k]=t;
    }
    double knightProbability(int &n, int &k, int &row, int &column) {
        
vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
  double ans=solve(n,k,row,column,dp);
       return ans;
        
    }
};