class Solution {
public:
    int lcs(string &s,string &r,int n,int m,vector<vector<int>> &dp)
    {
        if(n==0 || m==0)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(s[n-1]==r[m-1])
        {
           return dp[n][m]=1+lcs(s,r,n-1,m-1,dp);
        }
        return dp[n][m]=max({lcs(s,r,n-1,m,dp),lcs(s,r,n,m-1,dp)});
        
    }
    int minInsertions(string &s) {
        string r=s;
        reverse(r.begin(),r.end());
        vector<vector<int>> dp(s.size()+1,vector<int>(r.size()+1,-1));
        return s.size()-lcs(s,r,s.size(),r.size(),dp);
        
    }
};