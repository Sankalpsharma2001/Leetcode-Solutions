class Solution {
public:
    int solve(vector<int>& jobDifficulty,int i,int d,vector<vector<int>> &dp)
    {
        int n=jobDifficulty.size();
        if(i==n && d==0) return 0;
        if(i==n || d==0 || n-i<d) return 1e9;
        if(dp[i][d]!=-1)
            return dp[i][d];
        int ans=1e9,mx=-1e9;
        for(int cut=i;cut<n;cut++)
        {
            mx=max(mx,jobDifficulty[cut]);
            ans=min(ans,mx+solve(jobDifficulty,cut+1,d-1,dp));
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=jobDifficulty.size();
        if(d>n) return -1;
        vector<vector<int>> dp(n+1,vector<int>(11,-1));
        return solve(jobDifficulty,0,d,dp);
        
    }
};