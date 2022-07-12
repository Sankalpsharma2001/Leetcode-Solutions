// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  long long int dp[101][101];
  int mod=1e9+7;
   long long int solve(int i,int j,int m,int n)
   {
       if(i<1 || j<1 || i>m || j>n)return 0;
       if(i==m and j==n) return 1;
     if(dp[i][j]!=-1)
     return dp[i][j]%mod;
     return dp[i][j]=(solve(i+1,j,m,n)%mod+solve(i,j+1,m,n)%mod)%mod;
   }
    long long int numberOfPaths(int m, int n){
        // code here
memset(dp,-1,sizeof(dp));
        return solve(1,1,m,n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends