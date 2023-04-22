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
    int lcs(string s, string r, vector<vector<int>>&dp){
        int n = s.size();
        // for(int i = 0; i <= n; i++){
        //     for(int j = 0; j <= n; j++){
        //         if(i == 0 || j == 0)
        //         dp[i][j] = 0;
        //     }
        // }
         vector<int> prev(n+1,0),cur(n+1,0);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == r[j-1]){
                    cur[j] = 1 + prev[j-1];
                } else{
                    cur[j] = max(prev[j],cur[j-1]);
                }
            }
            prev=cur;
        }
        return prev[n];
    }
    int minInsertions(string &s) {
        string r=s;
        reverse(r.begin(),r.end());
        vector<vector<int>> dp(s.size()+1,vector<int>(r.size()+1,-1));
        // return s.size()-lcs(s,r,s.size(),r.size(),dp);
         return s.size()-lcs(s,r,dp);
       
    }
};