class Solution {
public:
    int ceil_function(double val)
    {
        int a=val; 
        if(a==val)
        {
            return val; 
        }
        
        return a+1; 
    }
    double dfs(vector<int>& dist, int speed,int skips,int i,vector<vector<double>> &dp)
    {
        if(i<0) return 0;
        if(dp[i][skips]!=-1)
            return dp[i][skips];
        double time=(double)(dist[i])/speed*1.0;
        double val= ceil_function( (double) dfs(dist , speed , skips , i-1,dp) + time);
        if(skips>0)
        {
            val=min(val,(double)dfs(dist,speed,skips-1,i-1,dp)+time-1e-9);
        }
        return dp[i][skips]=val;
    }
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n=dist.size();
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1));
        
        for(int i=0;i<n;i++)
        {
            if(dfs(dist,speed,i,n-1,dp)<=hoursBefore)
            {
                return i;
            }
        }
        return -1;
    }
};