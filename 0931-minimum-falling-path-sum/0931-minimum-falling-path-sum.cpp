class Solution {
public:
//     int dfs(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp)
//     {
//         if( j<0 || i>=matrix.size() || j>=matrix[0].size())
//             return 1e9;
//         if(i==matrix.size()-1)
//             return matrix[i][j];
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//        int a=matrix[i][j]+dfs(matrix,i+1,j-1,dp);
//         int b=matrix[i][j]+dfs(matrix,i+1,j,dp);
//         int c=matrix[i][j]+dfs(matrix,i+1,j+1,dp);
//         return dp[i][j]=min({a,b,c});
//     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int ans=1e9;
        // vector<vector<int>> dp(1001,vector<int>(1001,-1));
        // for(int i=0;i<matrix[0].size();i++)
        // {
        //     int x=dfs(matrix,0,i,dp);
        //     ans=min(ans,x);
        // }
        // return ans;
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(1001,vector<int>(1001,0));
        for(int i=0;i<matrix[0].size();i++)
        {
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                int a=1e9,b=1e9,c=1e9;
                if(j>0)
                 a=matrix[i][j]+dp[i+1][j-1];
            
           b=matrix[i][j]+dp[i+1][j];
         if(j+1<m)
                c=matrix[i][j]+dp[i+1][j+1];
        dp[i][j]=min({a,b,c});
            }
        }
        
        for(int i=0;i<m;i++)
        {
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};