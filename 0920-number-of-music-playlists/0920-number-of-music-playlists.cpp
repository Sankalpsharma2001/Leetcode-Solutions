class Solution {
public:
    int mod=1e9+7;
    long long calculate(int goal,int used,int n,int k,vector<vector<int>> &dp)
    {
        if(goal==0)
        {
            // at least once every song played
           return n==used;
        }
        if(dp[goal][used]!=-1) return dp[goal][used];  
        // then we can use only after k songs have been played
        long long usingUsed=max(0,used-k)*calculate(goal-1,used,n,k,dp)%mod; 
        // using new song then we are multiplyin other remaining song 
        long long usingNew=(n-used)>0?(n-used)*calculate(goal-1,used+1,n,k,dp)%mod:0;    
        long long temp=(usingUsed+usingNew)%mod;
        return dp[goal][used]=temp;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>> dp(goal+1,vector<int>(n+1,-1));
        return calculate(goal,0,n,k,dp);         
    }
};