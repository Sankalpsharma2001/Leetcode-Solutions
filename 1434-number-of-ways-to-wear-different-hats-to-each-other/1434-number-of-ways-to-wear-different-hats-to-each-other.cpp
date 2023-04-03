class Solution {
public:
    int mod=1e9+7;
    int solve(int hat,int people, unordered_map<int,vector<int>> &m,vector<vector<int>> &dp)
    {
        if(people==dp.size()-1) return 1;
        if(hat>40) return 0;
        if(dp[people][hat]!=-1) return dp[people][hat];
        
        int ans=solve(hat+1,people,m,dp)%mod;
        for(auto &it:m[hat])
        {
            if((people & (1<<it))==0)
            {
                ans=(ans%mod+solve(hat+1,people|(1<<it),m,dp)%mod)%mod;
            }
        }
        
        return dp[people][hat]=ans%mod;
        
    }
    int numberWays(vector<vector<int>>& hats) {
        int n=hats.size();
        vector<vector<int>> dp(1<<n,vector<int>(41,-1));
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++)
        {
            for(auto &it:hats[i])
            {
                m[it].push_back(i);
            }
        }
        
        int people=0;
        return solve(1,people,m,dp)%mod;
    }
};