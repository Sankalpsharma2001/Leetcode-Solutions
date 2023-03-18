//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
//     int solve(int i,int j,vector<vector<int>>& triangle, vector<vector<int>> &dp)
//     {
//      int col=triangle[i].size();
//      int n=triangle.size();
//         if(i==n-1)
//         {
//             return triangle[i][j];
            
//         }
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//         int d=triangle[i][j]+solve(i+1,j,triangle,dp);
//         int dr=triangle[i][j]+solve(i+1,j+1,triangle,dp);
//         return dp[i][j]=min(d,dr);
        
//     }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
            n=triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
          // return solve(0,0,triangle,dp);
      
        
//         vector<vector<int>> dp(n,vector<int>(n,0));
//         for(int i=0;i<n;i++)
//         {
//             dp[n-1][i]=triangle[n-1][i];
//         }
//         for(int i=n-2;i>=0;i--)
//         {
//             for(int j=i;j>=0;j--)
//             {
//                 int d=triangle[i][j]+dp[i+1][j];
//                 int dr=triangle[i][j]+dp[i+1][j+1];
//                 dp[i][j]=min(d,dr);
//             }
//         }
        
//         return dp[0][0];
        
        
          vector<int> v(n,0),cur(n,0);
        for(int i=0;i<n;i++)
        {
            v[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int d=triangle[i][j]+v[j];
                int dr=triangle[i][j]+v[j+1];
                cur[j]=min(d,dr);
            }
            v=cur;
        }
        
        return v[0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends