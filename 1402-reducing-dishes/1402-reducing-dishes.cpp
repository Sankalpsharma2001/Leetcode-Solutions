class Solution {
public:
    int solve(vector<int>& satisfaction,int idx,int time,vector<vector<int>> &dp)
    {
        if(idx>=satisfaction.size()) return 0;
        if(dp[idx][time]!=-1)
            return dp[idx][time];
        
      int a=solve(satisfaction,idx+1,time,dp);
      int b=(satisfaction[idx]*time+solve(satisfaction,idx+1,time+1,dp));
        return dp[idx][time]=max(a,b);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        int ans=0;
       vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(satisfaction,0,1,dp);
        
    }
};