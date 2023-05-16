class Solution {
public:
     int solve(string &s,string &p,int n,int m,vector<vector<int>> &dp)
    {
         
        if(n<0 and m<0) return 1;
        if(n>=0 and m<0) return 0;
         
         if(n<0 and m>=0)
         {
             for(int i=0;i<=m;i++)
             {
                 if(p[i]!='*')
                     return 0;
             }
             return 1;
         }
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n]==p[m])
         dp[n][m]=solve(s,p,n-1,m-1,dp);
        else if(p[m]=='?')
            dp[n][m]=solve(s,p,n-1,m-1,dp);
        else if(p[m]=='*')
           dp[n][m]=solve(s,p,n-1,m,dp)  || solve(s,p,n,m-1,dp);
        else
            return dp[n][m]=0;
         return dp[n][m];
    }
    bool isMatch(string s, string p) {
vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
       return solve(s,p,s.size()-1,p.size()-1,dp);
// vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,0));
//        int n=s.size();
//         int m=p.size();
//         dp[0][0]=1;
//         for(int i=1;i<=n;i++)
//         {
//             dp[i][0]=0;
//         }
//         for(int i=1;i<=m;i++)
//         {
//             if(p[i-1]=='*')
//                 dp[0][i]=dp[0][i-1];
//             else
//                 dp[0][i]=0;
//         }
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=m;j++)
//             {
//                 if(s[i-1]==p[j-1] or p[j-1]=='?')
//                     dp[i][j]=dp[i-1][j-1];
//                 else if(p[j-1]=='*')
//                     dp[i][j]=dp[i-1][j]| dp[i][j-1] | dp[i-1][j-1];
//                 else dp[i][j]=0;
//             }
//         }
//         return dp[n][m];
    }
};