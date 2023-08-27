class Solution {
public:
  bool solve(vector<int> &stones,unordered_map<int,int> &m,int i,int k,vector<vector<int>> &dp)
  {
      if(k==0)
      return false;
      if(m.find(k+stones[i-1])==m.end())
      {
         return false;
      }
      else
      i=m[k+stones[i-1]];
    
    if(dp[i][k]!=-1)
    return dp[i][k];
  
   if(i==stones.size()-1)
   return true;
  return dp[i][k]=solve(stones,m,i+1,k-1,dp) || solve(stones,m,i+1,k,dp) || solve(stones,m,i+1,k+1,dp); 

  }
    bool canCross(vector<int>& stones) {
      unordered_map<int,int> m;
      vector<vector<int>> dp(2001,vector<int>(2001,-1));
      for(int i=0;i<stones.size();i++)
      {
          m[stones[i]]=i;

      }
      if(stones[1]!=1)
      return false;
      return solve(stones,m,1,1,dp);
        /*unordered_map<int,unordered_set<int>> m;
        m[stones[0]].insert(0);
        for(int i=0;i<stones.size();i++)
        {
            int jumps=stones[i];
            for(auto jump:m[jumps])
            {
                m[stones[i]+jump].insert(jump);
                
                m[stones[i]+jump+1].insert(jump+1);
                
                m[stones[i]+jump-1].insert(jump-1);
            }
        }
        return m[stones.back()].size();*/

    }
};