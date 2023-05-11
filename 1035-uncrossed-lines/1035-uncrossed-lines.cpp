class Solution {
public:
    int lcs(vector<int> &a,vector<int> &b,int n,int m,vector<vector<int>> &dp)
    {
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(a[n-1]==b[m-1])
             dp[n][m]=1+lcs(a,b,n-1,m-1,dp);
        else
            dp[n][m]=max(lcs(a,b,n-1,m,dp),lcs(a,b,n,m-1,dp));
        return dp[n][m];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
       return lcs(nums1,nums2,nums1.size(),nums2.size(),dp);
        
    }
};