class Solution {
public:
   int mod=1e9+7;
    int solve(int idx,int target,vector<vector<int>>& types,vector<vector<int>>& dp)
    {
        if(target<0) return 0;
        if(idx==types.size())
        {
            return target==0;
        }
        if(dp[idx][target]!=-1)
            return dp[idx][target];
        int ans=0;
        for(int i=0;i<=types[idx][0];i++)
        {
            ans=(ans+solve(idx+1,target-i*types[idx][1],types,dp))%mod;
            
        }
        return dp[idx][target]=ans%mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n=types.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(0,target,types,dp);
        // vector<int> dp(target+1,0);
        // dp[0]=1;
        // for(int i=0;i<types.size();i++)
        // {
        //     for(int j=target;j>=0;j--)
        //     {
        //         int val=types[i][0];
        //         for(int k=1;k<=val;k++)
        //         {
        //             int cnt=types[i][1];
        //             if(j-k*cnt>=0)
        //             dp[j]=(dp[j]+dp[j-k*cnt])%mod;
        //         }
        //     }
        // }
        // return dp[target]%mod;
    }
};