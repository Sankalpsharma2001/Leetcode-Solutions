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
        // vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
      // int ans=solve(coins,amount,coins.size()-1,dp);
       vector<int> dp(amount+1,1e9);
     
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<=amount;j++)
           {
               if(j==0)
               {
                   dp[j]=0;
                   continue;
               }
               if(coins[i]<=j)
               {
                   dp[j]=min(dp[j],1+dp[j-coins[i]]);
               }
               
           }
       }
        int ans=dp[amount];
      return (ans<1e9)?ans:-1;   
    }
};