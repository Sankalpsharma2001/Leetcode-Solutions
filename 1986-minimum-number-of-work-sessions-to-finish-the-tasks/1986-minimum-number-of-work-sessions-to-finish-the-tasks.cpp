class Solution {
public:
    int dp[20][1<<16];
    int solve(int time,int mask,vector<int> &tasks,int &sessionTime)
    {
         int n=tasks.size();
        if(mask==((1<<n)-1)) return 0;
        if(dp[time][mask]!=-1) return dp[time][mask];
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i)) continue;
            if(time+tasks[i]<=sessionTime)
            {
                ans=min(ans,solve(time+tasks[i],mask|(1<<i),tasks,sessionTime));
            }
            else
                ans=min(ans,1+solve(tasks[i],mask|(1<<i),tasks,sessionTime));
        }
        return dp[time][mask]=ans;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n=tasks.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,tasks,sessionTime)+1;
    }
};