class Solution {
public:
    int n,m;
    int minDif(int row,int sum,vector<vector<int>>& mat, int target,  vector<vector<int>> &dp)
    {
      if(row>=n)
      {
          return abs(target-sum);
      }
        if(dp[row][sum]!=-1)
            return dp[row][sum];
        int temp=INT_MAX;
        for(int col=0;col<m;col++)
        {
            temp=min(temp,minDif(row+1,sum+mat[row][col],mat,target,dp));
        }
        return dp[row][sum]=temp;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
         n=mat.size(),m=mat[0].size();
        vector<vector<int>> dp(71,vector<int>(5000,-1));
        return minDif(0,0,mat,target,dp);
    }
};