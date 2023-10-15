#define ll long long
class Solution {
public:
  int mod=1e9+7;
    ll solve(int steps,int len,int i,vector<vector<ll>> &dp)
    {
        if(steps==0 && i==0) return 1;
        if(i<0 || i>=len || steps==0 || i>steps) return 0;
        if(dp[i][steps]!=-1) return dp[i][steps];
        return dp[i][steps]=(solve(steps-1,len,i+1,dp)%mod+solve(steps-1,len,i-1,dp)%mod+solve(steps-1,len,i,dp)%mod)%mod;

    }
    int numWays(int steps, int arrLen) {
        vector<vector<ll>> dp(501,vector<ll>(501,-1));
        return solve(steps,arrLen,0,dp);
    }
};