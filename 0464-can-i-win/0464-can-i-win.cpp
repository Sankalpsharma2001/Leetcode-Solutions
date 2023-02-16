class Solution {
public:
     // dp[key]: memorized game result when pool state = key
  // 0: un-computed; 1: I win; -1: I lose
    int dp[1<<20]={};
    // k: current game state
     // t: remaining total to reach
    bool dfs(int mx,int t,int k)
    {
        if(dp[k]!=0)
            return dp[k]>0;
        if(t<=0) return false;
        for(int i=0;i<mx;i++)
        {
            // if (i+1) is available to pick and my opponent can't win after I picked, I win!
       // the i-th bit of k, i.e., k&(1<<i) represents the availability of number i+1     
            if(!(k&(1<<i)) && !dfs(mx,t-i-1,k|(1<<i))) // dfs give false means i+1 not win so i win the game
            {
                dp[k]=1;
                return true;
            }
        }
           // Otherwise, I will lose
        dp[k]=-1;
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
     
        int total=(maxChoosableInteger*(maxChoosableInteger+1))/2;  // sum of entire choosable pool
         // I just pick 1 to win
        if(desiredTotal<2)
            return true;
          // Total is too large, nobody can win
       if(desiredTotal>total)
           return false;
          // Total happens to match sum, whoever picks at odd times wins
        if(total==desiredTotal)
        {
            return maxChoosableInteger%2;
        }
        return dfs(maxChoosableInteger,desiredTotal,0);
        
    }
};