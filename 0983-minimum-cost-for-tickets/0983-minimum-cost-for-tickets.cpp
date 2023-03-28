class Solution {
public:
    int solve(int i,vector<int>& days, vector<int>& costs,vector<int> &vis,vector<int> &dp)
    {
        if(i>365) return 0;
        if(dp[i]!=-1)
            return dp[i];
        if(vis[i]==0)
        {
            return solve(i+1,days,costs,vis,dp);
        }
        return dp[i]=min({costs[0]+solve(i+1,days,costs,vis,dp),
            costs[1]+solve(i+7,days,costs,vis,dp),
                    costs[2]+solve(i+30,days,costs,vis,dp)
            });
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,-1),vis(366,0);
        for(auto &it:days)
        {
            vis[it]=1;
        }
        return solve(0,days,costs,vis,dp);
        // vector<int> dp(366,1e9);
        // dp[0]=0;
        // for(int i=1;i<=365;i++)
        // {
        //     if(find(days.begin(),days.end(),i)==days.end())
        //     {
        //         dp[i]=dp[i-1];
        //     }
        //     else
        //     {
        //         dp[i]=min({dp[i],dp[max(i-1,0)]+costs[0],dp[max(i-7,0)]+costs[1],
        //                    dp[max(i-30,0)]+costs[2]});
        //     }
        // }
        // return dp[365];
    }
};