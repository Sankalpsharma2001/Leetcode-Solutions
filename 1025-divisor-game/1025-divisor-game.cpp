class Solution {
public:
    bool divisorGame(int n) {
     vector<int> dp(n+1,0);
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(i%j==0)
                {
                    dp[i]=dp[i]|| !dp[i-j];
                }
            }
        }
        return dp[n];
    }
};