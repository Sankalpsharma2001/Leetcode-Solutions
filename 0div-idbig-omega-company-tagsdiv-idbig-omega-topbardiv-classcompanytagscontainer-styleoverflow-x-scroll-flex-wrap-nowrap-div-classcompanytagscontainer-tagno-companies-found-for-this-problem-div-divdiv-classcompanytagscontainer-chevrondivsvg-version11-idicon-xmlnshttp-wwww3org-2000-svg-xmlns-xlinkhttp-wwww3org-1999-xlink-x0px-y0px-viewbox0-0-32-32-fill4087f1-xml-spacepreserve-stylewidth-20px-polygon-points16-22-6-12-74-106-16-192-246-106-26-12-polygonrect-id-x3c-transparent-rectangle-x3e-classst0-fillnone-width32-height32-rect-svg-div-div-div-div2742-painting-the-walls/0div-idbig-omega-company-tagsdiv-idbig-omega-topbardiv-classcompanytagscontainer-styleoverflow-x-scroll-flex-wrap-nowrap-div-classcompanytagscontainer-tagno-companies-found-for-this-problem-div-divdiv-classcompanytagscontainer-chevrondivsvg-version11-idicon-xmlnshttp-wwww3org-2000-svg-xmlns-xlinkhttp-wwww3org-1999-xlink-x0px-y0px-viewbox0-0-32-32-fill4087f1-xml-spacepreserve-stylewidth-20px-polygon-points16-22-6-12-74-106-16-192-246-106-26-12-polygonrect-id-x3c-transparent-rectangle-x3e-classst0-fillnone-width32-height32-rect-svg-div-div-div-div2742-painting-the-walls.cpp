class Solution {
public:

    int solve(int i,int t,vector<int>& cost, vector<int>& time,vector<vector<int>> &dp)
    {
        int n=cost.size();
        if(i==n) return t>=0?0:1e9;
        if(dp[i][t+500]!=-1) return dp[i][t+500];
       
         int take=cost[i]+solve(i+1,t+time[i],cost,time,dp);
        
         int nottake=solve(i+1,t-1,cost,time,dp);
      
        return dp[i][t+500]=min(take,nottake);
       
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        int tt=accumulate(time.begin(),time.end(),0);
        vector<vector<int>> dp(n+1,vector<int>(tt+501,-1));
        return solve(0,0,cost,time,dp);
    
    }
};