class Solution {
public:
    int solve(vector<int> &piles,int st,int end,vector<vector<int>> &dp)
    {
        if(st>end) return 0;
        if(dp[st][end]!=-1) return dp[st][end];
        int x=piles[st]+solve(piles,st+1,end,dp);
        int y=piles[end]+solve(piles,st,end-1,dp);
        return dp[st][end]=max(x,y);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int s=0;
        for(auto &it:piles)
            s+=it;
        
        int f=solve(piles,0,n-1,dp);
        if(s-f<=f) return true;
        return false;
        
    }
};