class Solution {
public:
    int mod=1e9+7;
    int dp[101][101][101];
    int solve(int pos,int count,int profit,int n,int minProfit, vector<int>& group, vector<int>& profits)
    {
      if (pos == group.size()) {
            // If profit exceeds the minimum required; it's a profitable scheme.
            return profit >= minProfit;
        }   
         if (dp[pos][count][profit] != -1) {
            return dp[pos][count][profit];
        }
          // Ways to get a profitable scheme without this crime.
        int totalWays = solve(pos + 1, count, profit, n, minProfit, group, profits);
         if (count + group[pos] <= n) {
            // Adding ways to get profitable schemes, including this crime.
            totalWays += solve(pos + 1, count + group[pos], min(minProfit, profit + profits[pos]), n, minProfit, group, profits)%mod;
        }
         return dp[pos][count][profit] = totalWays % mod;
    }
   int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,n,minProfit,group,profit);
        
        
    }
};