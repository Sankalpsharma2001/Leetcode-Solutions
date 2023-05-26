class Solution {
public:
    int help(int i,int M,vector<int> &p,vector<vector<int>> &dp)
    {
         if(i>=p.size()) return 0;
        if(dp[i][M]!=-1) return dp[i][M];
        int sum=0;
        int ans=INT_MIN;
        for(int j=0;j<2*M;j++)
        {
            if(i+j<p.size()) sum+=p[i+j];
            ans=max(ans,sum-help(i+j+1,max(M,j+1),p,dp));
        }
        return dp[i][M]=ans;
        
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int x=help(0,1,piles,dp);// alice stone-bob stone
        int s=accumulate(piles.begin(),piles.end(),0); // alice+bob stone
        return (s+x)/2;
        
    }
};