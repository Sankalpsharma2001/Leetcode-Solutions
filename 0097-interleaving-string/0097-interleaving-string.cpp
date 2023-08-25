class Solution {
public:
   
    int solve(string &s1,string &s2,string &s3,int n,int m,int l,vector<vector<int>> &dp)
    {
        if(l==0) return 1;
        if(dp[n][m]!=-1) return dp[n][m];
        int a=0,b=0;
        if(n-1>=0 and s1[n-1]==s3[l-1])
        {
            a=solve(s1,s2,s3,n-1,m,l-1,dp);
        }
        if(m-1>=0 and s2[m-1]==s3[l-1])
        {
            b=solve(s1,s2,s3,n,m-1,l-1,dp);
        }
        return dp[n][m]=a|b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
         vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        if(s3.size()<s1.size()+s2.size()) return false;
      
        return solve(s1,s2,s3,s1.size(),s2.size(),s3.size(),dp);
        
    }
};