class Solution {
public:
    int dfs(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp)
    {
        if( j<0 || i>=matrix.size() || j>=matrix[0].size())
            return 1e9;
        if(i==matrix.size()-1)
            return matrix[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        
       int a=matrix[i][j]+dfs(matrix,i+1,j-1,dp);
        int b=matrix[i][j]+dfs(matrix,i+1,j,dp);
        int c=matrix[i][j]+dfs(matrix,i+1,j+1,dp);
        return dp[i][j]=min({a,b,c});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=1e9;
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        for(int i=0;i<matrix[0].size();i++)
        {
            int x=dfs(matrix,0,i,dp);
            ans=min(ans,x);
        }
        return ans;
    }
};