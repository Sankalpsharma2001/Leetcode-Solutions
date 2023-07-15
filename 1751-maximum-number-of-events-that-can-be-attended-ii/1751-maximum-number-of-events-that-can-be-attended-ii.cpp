class Solution {
public:
    int dfs(int i,int k,vector<vector<int>> &e,vector<vector<int>> &dp)
    {
        int n=e.size();
        if(i==n) return 0;
        if(k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int idx;
        for(idx=i+1;idx<n;idx++)
        {
            if(e[i][1]<e[idx][0]) break;
        }
        return dp[i][k]=max(e[i][2]+dfs(idx,k-1,e,dp),dfs(i+1,k,e,dp));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return dfs(0,k,events,dp);
    }
};