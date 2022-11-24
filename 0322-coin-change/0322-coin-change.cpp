class Solution {
public:
    int solve(vector<int> &coins,int amount,int n,vector<vector<int>> &dp)
    {
        if(amount==0) return 0;
        if(n<0 || amount<0)
            return 1e9;
        if(dp[n][amount]!=-1)
            return dp[n][amount];
        int a=1+solve(coins,amount-coins[n],n,dp);
        int b=solve(coins,amount,n-1,dp);
        return dp[n][amount]=min(a,b);
    }
    int coinChange(vector<int>& coins, int amount) {
      int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
      sort(coins.begin(),coins.end());
      int ans=solve(coins,amount,coins.size()-1,dp);
      return (ans<1e9)?ans:-1;   
    }
};