class Solution {
public:
    int ans=0;
    int solve(string s,string t,int n,int m)
    {
        if(m>n) return 0;
       unsigned long long int dp[1001][1001];
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=1;
        }
        for(int i=1;i<=m;i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {    
                 if(t[i-1]==s[j-1])
                {
                    dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
    int solveRecursion(string &s,string &t,int n,int m, vector<vector<int>> &dp)
    {
        if(n==0 && m==0) return 1;
        if(m==0) return 1;
        if(n==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n-1]==t[m-1])
            return dp[n][m]=solveRecursion(s,t,n-1,m-1,dp)+solveRecursion(s,t,n-1,m,dp);
        return dp[n][m]=solveRecursion(s,t,n-1,m,dp);
            
        
    }
    int numDistinct(string &s, string &t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
       return solveRecursion(s,t,s.size(),t.size(),dp);
        
    }
};